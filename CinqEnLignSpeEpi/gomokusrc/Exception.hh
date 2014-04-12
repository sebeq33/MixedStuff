//
// exception.hh for exception.hh in /home/bequig_s//workspace/ia/TP2
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Tue May 28 16:06:21 2013 sebastien bequignon
// Last update Tue May 28 16:06:57 2013 sebastien bequignon
//

#ifndef EXCEPTION_H_
# define EXCEPTION_H_

// -------------------------

#include <exception>
#include <string>

# define DEFINE_EXCEPTION(ExName, Msg)			\
  class ExName : public std::exception			\
  {							\
  private:						\
    std::string		_what;				\
  public:						\
    ExName(std::string const& what = Msg): _what(what)	\
    {}							\
    virtual ~ExName() throw()				\
    {}							\
    virtual const char *	what() const throw()	\
    {							\
      return (_what.c_str());				\
    }							\
  };

// -------------------------


#endif /* !EXCEPTION_H_ */
