//
// Process.hh for Process.hh in /home/bequig_s//workspace/c++/plazza/plazza
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Sun Apr 21 09:46:48 2013 sebastien bequignon
// Last update Sun Apr 21 22:47:38 2013 sebastien bequignon
//

#ifndef PROCESS_H_
# define PROCESS_H_

#include <sys/wait.h>
#include <string>
#include "NamedPipes.hh"
#include "ScopedLock.hh"

template <typename T = int, typename U = unsigned int>
class Process
{
private:
  pid_t pid;
  int id;
  Mutex mutex;
  NamedPipes in;
  NamedPipes out;

public:
  Process(int _id)
    : pid(-1), id(_id), in(id * 2), out((id * 2) + 1) //if id == 0 then in = 0 et out = 1
						      //if id == 1 then in = 2 et out = 3
  {
  }
  ~Process(){}
  bool start(void (*func)(Process &process, T val, T val2, U val3), T val, T val2, U val3)
  {
    if (pid != -1)
      return (false);
    if ((pid = fork()) == -1)
      return (false);
    if (pid == 0)
      {
	func(*this, val, val2, val3);
	_exit(0);
      }
    return (true);
  }
  void wait()
  {
    if (pid != 0 && pid != -1)
      {
	waitpid(pid, 0, 0);
	pid = -1;
      }
  }
  void operator>>(std::string &str)
  {
    ScopedLock lock(&mutex);

    if (pid == -1)
      throw std::exception();
    if (pid == 0)
      in >> str;
    else
      out >> str;
  }
  void operator<<(const std::string &str)
  {
    ScopedLock lock(&mutex);

    if (pid == -1)
      throw std::exception();
    if (pid == 0)
      out << str;
    else
      in << str;
  }
  bool isChild(void)
  {
    return (pid == 0);
  }
  int getId()
  {
    return (id);
  }
  void changeState(NamedPipes::State state)
  {
    ScopedLock lock(&mutex);

    if (pid == -1)
      throw std::exception();
    if (pid == 0)
      in.changeState(state);
    else
      out.changeState(state);
  }
};

#endif /* !PROCESS_H_ */
