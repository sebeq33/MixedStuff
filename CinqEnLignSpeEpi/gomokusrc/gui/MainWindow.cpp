#include <stdlib.h>
#include <time.h>

#include "MainWindow.hh"
#include "GomokuGui.hh"

MainWindow::MainWindow()
{
  srand(time(NULL));

  setWindowTitle(trUtf8("Gomoku"));
  createMenu();

  statusBarLabel = new QLabel(this);
  scorePlayer1 = new QLabel(this);
  scorePlayer2 = new QLabel(this);

  statusBarLabel->setStyleSheet("font: 12pt;");
  scorePlayer1->setStyleSheet("font: 12pt;");
  scorePlayer2->setStyleSheet("font: 12pt;");

  statusBar()->addPermanentWidget(scorePlayer1, 90);
  statusBar()->addPermanentWidget(scorePlayer2, 200);
  statusBar()->addPermanentWidget(statusBarLabel);

  qApp->setStyleSheet("QStatusBar::item { border : 0px solid black }");

  grid = new Grid(19, this);
  grid->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));

  connect(grid, SIGNAL(gameStateChanged(Gomoku::GameState, uint8_t, uint8_t)),
          this, SLOT(applyGameState(Gomoku::GameState, uint8_t, uint8_t)));

  windowLayout = new QHBoxLayout();
  windowLayout->addWidget(grid);

  centralWidget = new QWidget();
  centralWidget->setLayout(windowLayout);

  setCentralWidget(centralWidget);

  resize(QSize(800, 800));

  gridDrawer = new GomokuGui();
  grid->setDisplay(gridDrawer);
  grid->repaint();
  newGame();
}

MainWindow::~MainWindow()
{
  delete statusBarLabel;
  delete scorePlayer1;
  delete scorePlayer2;
  delete grid;
  delete windowLayout;
  delete gameMenu;
  delete newGameAction;
  delete quitAction;
  delete optionMenu;
  delete player1Menu;
  delete player1HumanAction;
  delete player1AIAction;
  delete player2Menu;
  delete player2HumanAction;
  delete player2AIAction;
  delete rulesMenu;
  delete doubleThree;
  delete breakableFive;
  delete takeStone;
  delete centralWidget;
}

void MainWindow::createMenu()
{
  gameMenu = new QMenu(trUtf8("&Partie"), this);
  menuBar()->addMenu(gameMenu);

  newGameAction = new QAction(trUtf8("&Nouvelle partie"), this);
  gameMenu->addAction(newGameAction);
  gameMenu->addSeparator();
  connect(newGameAction, SIGNAL(triggered(bool)), this, SLOT(newGame()));

  quitAction = new QAction(trUtf8("&Quitter"), this);
  gameMenu->addAction(quitAction);
  connect(quitAction, SIGNAL(triggered(bool)), qApp, SLOT(quit()));

  optionMenu = new QMenu(trUtf8("&Options"), this);
  menuBar()->addMenu(optionMenu);

  setFirstPlayer();
  setSecondPlayer();
  setRulesOptions();
}

void MainWindow::setFirstPlayer()
{
  player1Menu = new QMenu(trUtf8("&Noir"), this);
  optionMenu->addMenu(player1Menu);

  player1HumanAction = new QAction(trUtf8("Joueur &humain"), this);
  player1HumanAction->setCheckable(true);
  player1HumanAction->setChecked(true);
  player1Menu->addAction(player1HumanAction);
  connect(player1HumanAction, SIGNAL(triggered(bool)), this, SLOT(applyPlayMode()));

  player1AIAction = new QAction(trUtf8("&Intelligence artificielle"), this);
  player1AIAction->setCheckable(true);
  player1Menu->addAction(player1AIAction);
  connect(player1AIAction, SIGNAL(triggered(bool)), this, SLOT(applyPlayMode()));
}

void MainWindow::setSecondPlayer()
{
  player2Menu = new QMenu(trUtf8("&Blanc"), this);
  optionMenu->addMenu(player2Menu);

  player2HumanAction = new QAction(trUtf8("Joueur &humain"), this);
  player2HumanAction->setCheckable(true);
  player2HumanAction->setChecked(true);
  player2Menu->addAction(player2HumanAction);
  connect(player2HumanAction, SIGNAL(triggered(bool)), this, SLOT(applyPlayMode()));

  player2AIAction = new QAction(trUtf8("&Intelligence artificielle"), this);
  player2AIAction->setCheckable(true);
  player2Menu->addAction(player2AIAction);
  connect(player2AIAction, SIGNAL(triggered(bool)), this, SLOT(applyPlayMode()));
}

void MainWindow::setRulesOptions()
{
  rulesMenu = new QMenu(trUtf8("&Règles possibles"), this);
  optionMenu->addMenu(rulesMenu);

  doubleThree = new QAction(trUtf8("&Double trois"), this);
  doubleThree->setCheckable(true);
  rulesMenu->addAction(doubleThree);
  connect(doubleThree, SIGNAL(triggered(bool)), this, SLOT(applyDoubleThree()));

  breakableFive = new QAction(trUtf8("&Cinq cassable"), this);
  breakableFive->setCheckable(true);
  rulesMenu->addAction(breakableFive);
  connect(breakableFive, SIGNAL(triggered(bool)), this, SLOT(applyBreakableFive()));

  takeStone = new QAction(trUtf8("&Prise de pierres"), this);
  takeStone->setCheckable(true);
  takeStone->setChecked(true);
  rulesMenu->addAction(takeStone);
  connect(takeStone, SIGNAL(triggered(bool)), this, SLOT(applyTakeStone()));
}

void MainWindow::closeEvent(QCloseEvent *cEvent)
{
  cEvent->accept();
}

void MainWindow::newGame()
{
  uint r = (uint) ((double) rand() / (RAND_MAX) * 2) + 1;
  if (r == 1)
    grid->restart(Gomoku::PLAYER1);
  else
    grid->restart(Gomoku::PLAYER2);
  statusBarLabel->setStyleSheet("font: 12pt;");
}

void MainWindow::applyGameState(Gomoku::GameState st, uint8_t scoreP1, uint8_t scoreP2)
{
  switch (st)
    {
    case Gomoku::NOT_STARTED:
      statusBarLabel->setText(trUtf8("Aucune partie en cours.")); break ;

    case Gomoku::NO_WINNER:
      break;

    case Gomoku::DRAW:
      statusBarLabel->setText(trUtf8("Match null"));
      statusBarLabel->setStyleSheet("font: 15pt;");
      break ;

    case Gomoku::ERROR:
      statusBarLabel->setText(trUtf8("Tu ne peux pas jouer là.")); break ;

    case Gomoku::PLAYER1_TURN:
      if (grid->getTypePlayer(Gomoku::PLAYER1) == Gomoku::IA)
	{
	  if (grid->getTypePlayer(Gomoku::PLAYER2) == Gomoku::IA)
	    statusBarLabel->setText(trUtf8("En attente d'un déplacement de l'ordinateur (Noir)."));
	  else
	    statusBarLabel->setText(trUtf8("En attente d'un déplacement de l'ordinateur."));
	}
      else if (grid->getTypePlayer(Gomoku::PLAYER2) == Gomoku::HUMAN)
	statusBarLabel->setText(trUtf8("A vous (Noir)."));
      else
	statusBarLabel->setText(trUtf8("A vous."));
      break ;

    case Gomoku::PLAYER2_TURN:
      if (grid->getTypePlayer(Gomoku::PLAYER2) == Gomoku::IA)
	{
	  if (grid->getTypePlayer(Gomoku::PLAYER1) == Gomoku::IA)
	    statusBarLabel->setText(trUtf8("En attente d'un déplacement de l'ordinateur (Blanc)."));
	  else
	    statusBarLabel->setText(trUtf8("En attente d'un déplacement de l'ordinateur."));
	}
      else if (grid->getTypePlayer(Gomoku::PLAYER1) == Gomoku::HUMAN)
	statusBarLabel->setText(trUtf8("A vous (Blanc)."));
      else
	statusBarLabel->setText(trUtf8("A vous."));
      break ;

    case Gomoku::PLAYER1_WIN:
      if (grid->getTypePlayer(Gomoku::PLAYER1) == Gomoku::IA)
	{
	  if (grid->getTypePlayer(Gomoku::PLAYER2) == Gomoku::IA)
	    statusBarLabel->setText(trUtf8("L'ordinateur (Noir) a gagne."));
	  else
	    statusBarLabel->setText(trUtf8("Vous avez perdu"));
	}
      else if (grid->getTypePlayer(Gomoku::PLAYER2) == Gomoku::IA)
	statusBarLabel->setText(trUtf8("Vous avez gagné."));
      else
	statusBarLabel->setText(trUtf8("Noir a gagné."));
      statusBarLabel->setStyleSheet("font: 15pt;");
      break ;

    case Gomoku::PLAYER2_WIN:
      if (grid->getTypePlayer(Gomoku::PLAYER2) == Gomoku::IA)
	{
	  if (grid->getTypePlayer(Gomoku::PLAYER1) == Gomoku::IA)
	    statusBarLabel->setText(trUtf8("L'ordinateur (Blanc) a gagne."));
	  else
	    statusBarLabel->setText(trUtf8("Vous avez perdu"));
	}
      else if (grid->getTypePlayer(Gomoku::PLAYER2) == Gomoku::IA)
	statusBarLabel->setText(trUtf8("Vous avez gagné."));
      else
	statusBarLabel->setText(trUtf8("Blanc a gagné."));
      statusBarLabel->setStyleSheet("font: 15pt;");
      break ;

    }
  scorePlayer1->setText(QString("Noir : %1").arg(scoreP1));
  scorePlayer2->setText(QString("Blanc : %1").arg(scoreP2));
}

void MainWindow::applyPlayMode()
{
  int r = QMessageBox::question(this, trUtf8("Attention"),
				trUtf8("Vous venez de modifier un des joueurs, souhaitez vous redémarrer la partie ?"),
				QMessageBox::Ok | QMessageBox::No | QMessageBox::Cancel,
				QMessageBox::Cancel);
  if (r == QMessageBox::Cancel)
    {
      if (sender() == player1HumanAction)
	player1HumanAction->setChecked(!player1HumanAction->isChecked());
      else if (sender() == player2HumanAction)
	player2HumanAction->setChecked(!player2HumanAction->isChecked());
      else if (sender() == player1AIAction)
	player1AIAction->setChecked(!player1AIAction->isChecked());
      else if (sender() == player2AIAction)
	player2AIAction->setChecked(!player2AIAction->isChecked());
      return ;
    }

  if (sender() == player1HumanAction)
    {
      player1HumanAction->setChecked(true);
      player1AIAction->setChecked(false);
    }

  else if (sender() == player1AIAction)
    {
      player1HumanAction->setChecked(false);
      player1AIAction->setChecked(true);
    }

  else if (sender() == player2HumanAction)
    {
      player2HumanAction->setChecked(true);
      player2AIAction->setChecked(false);
    }

  else if (sender() == player2AIAction)
    {
      player2HumanAction->setChecked(false);
      player2AIAction->setChecked(true);
    }

  if (r == QMessageBox::Ok)
    newGame();
}

void    MainWindow::applyDoubleThree()
{
  int r = QMessageBox::question(this, trUtf8("Attention"),
				trUtf8("Vous venez de modifier les règles, souhaitez vous redémarrer la partie ?"),
				QMessageBox::Ok | QMessageBox::No | QMessageBox::Cancel,
				QMessageBox::Cancel);
  if (r != QMessageBox::Cancel)
    {
      grid->setRules(Gomoku::DOUBLETHREE, doubleThree->isChecked());
      if (r == QMessageBox::Ok)
	newGame();
    }
  else
    doubleThree->setChecked(!doubleThree->isChecked());
}

void    MainWindow::applyBreakableFive()
{
  int r = QMessageBox::question(this, trUtf8("Attention"),
				trUtf8("Vous venez de modifier les règles, souhaitez vous redémarrer la partie ?"),
				QMessageBox::Ok | QMessageBox::No | QMessageBox::Cancel,
				QMessageBox::Cancel);
  if (r != QMessageBox::Cancel)
    {
      grid->setRules(Gomoku::BREAKABLE_FIVE, breakableFive->isChecked());
      if (r == QMessageBox::Ok)
	newGame();
    }
  else
    breakableFive->setChecked(!breakableFive->isChecked());
}

void    MainWindow::applyTakeStone()
{

  int r = QMessageBox::question(this, trUtf8("Attention"),
				trUtf8("Vous venez de modifier les règles, souhaitez vous redémarrer la partie ?"),
				QMessageBox::Ok | QMessageBox::No | QMessageBox::Cancel,
				QMessageBox::Cancel);
  if (r != QMessageBox::Cancel)
    {
      grid->setRules(Gomoku::TAKESTONE, takeStone->isChecked());
      if (r == QMessageBox::Ok)
	newGame();
    }
  else
    takeStone->setChecked(!takeStone->isChecked());
}
