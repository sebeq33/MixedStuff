#ifndef		MUTEX_H_
# define	MUTEX_H_

#ifdef WIN32
# include <windows.h>
#  pragma comment(lib, "Ws2_32.lib")
# else /* UNIX */
# include <pthread.h>
# include <stddef.h>
# endif
class Mutex
{
public:
  Mutex();
  virtual ~Mutex();
  virtual void lock(void);
  virtual void unlock(void);
# ifdef WIN32
  virtual HANDLE	getMutex() const;
# else
  virtual pthread_mutex_t	*getMutex() const;
# endif

private:
# ifdef WIN32
  HANDLE mutex;
# else
  pthread_mutex_t mutex;
# endif
  Mutex(Mutex const &);
  Mutex &operator=(Mutex const &);
};

#endif /* !MUTEX_H_ */
