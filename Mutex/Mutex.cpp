#include "Mutex.hh"
#include <iostream>

Mutex::Mutex()
{
# ifdef WIN32
  if ((mutex = CreateMutex(0, FALSE, 0)) == NULL)
    std::cout << "Init error"<< std::endl;
# else
  if (pthread_mutex_init(&mutex, NULL) != 0)
    std::cout << "Init error"<< std::endl;
# endif
}

Mutex::~Mutex()
{
# ifdef WIN32
  CloseHandle(mutex);
# else
  pthread_mutex_destroy(&mutex);
# endif
}

void Mutex::lock(void)
{
# ifdef WIN32
  WaitForSingleObject(mutex, INFINITE);
# else
  pthread_mutex_lock(&mutex);
# endif
}

void Mutex::unlock(void)
{
# ifdef WIN32
  ReleaseMutex(mutex);
# else
  pthread_mutex_unlock(&mutex);
# endif
}

# ifdef WIN32
HANDLE	Mutex::getMutex() const
{
  return (mutex);
}

# else
pthread_mutex_t	*Mutex::getMutex() const
{
  return (&mutex);
}

# endif
