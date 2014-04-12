//
// IMonitorModule.hh for MyGKrellM in /home/canda_j//piscine/tek2/rush3/piscine_cpp_rush3-2016-bequig_s/src/interface
//
// Made by julien canda
// Login   <canda_j@epitech.net>
//
// Started on  Sat Jan 26 10:51:01 2013 julien canda
// Last update Sun Jan 27 07:07:39 2013 sebastien bequignon
//

#ifndef IMONITORMODULE_H_
# define IMONITORMODULE_H_

enum TypeModule
  {
    NAME,
    MEM,
    CORE,
    DATETIME,
    NET,
    SYSTEM_VERSION
  };

class IMonitorModule
{
public:
  virtual ~IMonitorModule() {};
  virtual void updateData() = 0;
  virtual TypeModule getType() const = 0;
};

#endif /* !IMONITORMODULE_H_ */
