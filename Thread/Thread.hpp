//
// Thread.hpp for Thread.hpp in /home/bequig_s//workspace/rtype/include/Thread
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Sun Jul 28 17:59:50 2013 sebastien bequignon
// Last update Sun Jul 28 18:55:39 2013 sebastien bequignon
//

#ifndef THREAD_H_
# define THREAD_H_

# ifdef WIN32
# include <windows.h>
#  pragma comment(lib, "Ws2_32.lib")
# else /* UNIX */
# include <pthread.h>
# include <stddef.h>
# endif

#include <stdint.h>
#include <exception>

class THException : public std::exception
{
protected:
  const char  *_message;

public:
  THException(const char *message) : _message(message)
  {}
  virtual ~THException() throw() {}
  virtual const char *what() const throw()
  {
    return (_message);
  }
};

template <typename T, typename U = int32_t>
class Thread
{

  /*
  ** =======================
  **         DEFINE
  ** =======================
  */
public:
  enum ThreadState
    {
      CREATED,
      RUNNING,
      WAITING,
      JOINED
    };

private:
  typedef U (*ThreadFunc)(T);

  struct Param
  {
    U		ret;
    T		param;
    ThreadFunc  func;
    ThreadState state;
  };

  /*
  ** =======================
  **         PRIVATE
  ** =======================
  */

private:

  Thread(const Thread &);
  Thread &operator=(const Thread &);

  Param	paramSave;
  int32_t exitCode;

#ifdef WIN32
  HANDLE	thread;

  static DWORD WINAPI	tool_func(LPVOID param)
  {
    Param *p = reinterpret_cast<Param *>(param);

    if (p)
      {
	p->ret = p->func(p->param);
	p->state = WAITING;
	return (0);
      }
    return (1);
  }

  bool		destroy(void)
  {
    if (CloseHandle(thread))
         return (true);
    return (false);
  }
#else /* UNIX */

  pthread_t thread;

  static void *	tool_func(void *param)
  {
    Param *p = reinterpret_cast<Param *>(param);

    if (p)
      {
	p->ret = p->func(p->param);
	p->state = WAITING;
	return (reinterpret_cast<void *>(0));
      }
    return (reinterpret_cast<void *>(1));
  }

  bool		destroy(void)
  {
    return (this->wait());
  }
#endif

  /*
  ** =======================
  **         PUBLIC
  ** =======================
  */

public:
  Thread() : exitCode(0){this->paramSave.state = CREATED;}
  ~Thread() {this->destroy();}

  bool		operator()(ThreadFunc func, T param)
  {
    return (this->start(func, param));
  }

#ifdef WIN32
  bool		start(ThreadFunc func, T param)
  {
    if (this->paramSave.state == RUNNING)
      return (false);
    this->paramSave.func = func;
    this->paramSave.param = param;
    thread = ::CreateThread(NULL,
			  0,
			  &tool_func,
			  reinterpret_cast<void *>(&paramSave),
			  0,
			  NULL);
    if (thread != NULL)
      {
	      this->paramSave.state = RUNNING;
	      return (true);
      }
    return (false);
  }

  bool	wait()
  {
    if (this->paramSave.state != CREATED && this->paramSave.state != JOINED &&
	::WaitForSingleObject(thread, INFINITE) != WAIT_FAILED)
      {
          ::GetExitCodeThread(thread, reinterpret_cast<LPDWORD>(&(this->exitCode)));
	this->paramSave.state = JOINED;  
	return (true);
      }
    return (false);
  }

  static void	exitThread(int32_t exitCode)
  {
    ::ExitThread(exitCode);
  }

#else /* UNIX */

  bool		start(ThreadFunc func, T param)
  {
    bool	res;

    if (this->paramSave.state == RUNNING)
      return (false);
    this->wait();
    this->paramSave.func = func;
    this->paramSave.param = param;
    res = ::pthread_create(&thread,
			   NULL,
			   &tool_func,
			   reinterpret_cast<void *>(&paramSave));
    if (res == 0)
      {
	this->paramSave.state = RUNNING;
	return (true);
      }
    return (false);
  }

  bool		wait(void)
  {
    if (this->paramSave.state != CREATED && this->paramSave.state != JOINED
	&& ::pthread_join(thread, reinterpret_cast<void **>(&exitCode)) == 0)
      {
	this->paramSave.state = JOINED;
	return (true);
      }
    return (false);
  }

  static void	exitThread(int32_t exitCode)
  {
    ::pthread_exit(reinterpret_cast<void *>(exitCode));
  }

#endif
  U		getReturnvalue()
  {
    if (paramSave.state == CREATED || paramSave.state == RUNNING)
      throw (THException("Unable to retrieve exit code if not runned or while running"));
    return (this->paramSave.ret);
  }

  int32_t	getExitCode()
  {
    if (paramSave.state == CREATED || paramSave.state == RUNNING)
      throw (THException("Unable to retrieve exit code if not runned or while running"));
    return (this->exitCode);
  }

  ThreadState	getState() const
  {
    return (this->paramSave.state);
  }
};

#endif /* !THREAD_H_ */
