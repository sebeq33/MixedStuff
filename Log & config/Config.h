#ifndef CONFIG_H
#define CONFIG_H

#include <QDialog>
#include <fstream>
#include <string>
#include "babel.h"
#include "Convert.hpp"

class Babel;

namespace Ui
{
  class Config;
}

class Config : public QDialog
{
  Q_OBJECT

 public:
  explicit Config(Babel *parent);
  ~Config();
  const std::string &getHost() const;
  int16_t getPort() const;
  void setError(QString err);

 private:
  Ui::Config *ui;
  Babel *_parent;
  const char *configfile;
  bool validated;
  std::string host;
  std::string port;

  private slots:
  void on_cancelButton_clicked();
  void on_okButton_clicked();
};

#endif // CONFIG_H
