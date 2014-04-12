//
// ExceptionClass.hh for include in /home/sfez_a/Local/projects/c++/svn/babel/include
//
// Made by arthur sfez
// Login   <sfez_a@epitech.net>
//
// Started on  Mon May 13 15:06:59 2013 arthur sfez
// Last update Thu May 30 16:15:18 2013 quentin mangeon
//

#ifndef EXCEPTIONCLASS_HH_
# define EXCEPTIONCLASS_HH_

#include <exception>

# define DEFINE_EXCEPTION(ExName)			\
  class ExName : public std::exception			\
  {							\
  private:						\
    std::string		_what;				\
  public:						\
    ExName(std::string const& what): _what(what)	\
    {}							\
    virtual ~ExName() throw()				\
    {}							\
    virtual const char *	what() const throw()	\
    {							\
      return (_what.c_str());				\
    }							\
  };

# define DEFINE_EXCEPT_MSG(ExName, Message)			\
  class ExName : public std::exception				\
  {								\
  private:							\
    std::string		_what;					\
  public:							\
    ExName(std::string const& what = Message): _what(what)	\
    {}								\
    virtual ~ExName() throw()					\
    {}								\
    virtual const char *	what() const throw()		\
    {								\
      return (_what.c_str());					\
    }								\
  };

#endif /* !EXCEPTIONCLASS_HH_ */
