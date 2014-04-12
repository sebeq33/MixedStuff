#include <QApplication>
#include "MainWindow.hh"

int main(int ac, char **av)
{
	QApplication app(ac, av);
    MainWindow window;

    window.show();
	return (app.exec());
}
