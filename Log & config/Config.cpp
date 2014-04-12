#include "Config.h"
#include "ui_Config.h"

Config::Config(Babel *parent)
  :QDialog(parent)
  , ui(new Ui::Config)
  , _parent(parent)
  , configfile(".lastconnect.BabelConfig")
  , validated(false)
{
  std::fstream file(configfile, std::fstream::in);

  if (file.is_open())
  {
    file >> host;
    file >> port;
  }
  else
  {
    host = "127.0.0.1";
    port = "4242";
  }

  ui->setupUi(this);
  ui->hostEdit->setText(host.c_str());
  ui->portEdit->setText(port.c_str());
}

void Config::on_cancelButton_clicked()
{
  this->hide();
  validated = false;
}

void Config::on_okButton_clicked()
{
  QString host = ui->hostEdit->text();
  QString port = ui->portEdit->text();

  _parent->connect(host.toStdString(), port.toInt());
  validated = true;
  this->hide();
}

void Config::setError(QString err)
{
    ui->errorLabel->setText(err);
}

const std::string &Config::getHost() const
{
  return (host);
}

int16_t Config::getPort() const
{
  return (Convert<int16_t>::convert(port));
}

Config::~Config()
{
  if (validated)
    {
      std::fstream file(configfile, std::fstream::out | std::fstream::trunc);
      if (file.is_open())
	{
	  file << ui->hostEdit->text().toStdString() << std::endl;
	  file << ui->portEdit->text().toStdString() << std::endl;
	}
    }
  delete ui;
}
