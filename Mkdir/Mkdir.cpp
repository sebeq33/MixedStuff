//
// main.cpp for main.cpp in /tmp
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Fri May 10 10:44:33 2013 sebastien bequignon
// Last update Sat Jun  1 18:47:23 2013 sebastien bequignon
//

#include <iostream>

class Mkdir
{
public:
  static bool mkdir(const char *path);
  static bool direxist(const char *path);
};

#ifdef WIN32
#include <direct.h>
#include <Windows.h>

bool Mkdir::mkdir(const char *path)
{
  return (_mkdir(path) == 0);
}

bool Mkdir::direxist(const char *path)
{
  DWORD attr = GetFileAttributesA(path);
  return (attr != INVALID_FILE_ATTRIBUTES && attr & FILE_ATTRIBUTE_DIRECTORY);
}

#else
#include <sys/types.h>
#include <sys/stat.h>

bool Mkdir::mkdir(const char *path)
{
  return (::mkdir(path, 0700) == 0);
}

bool Mkdir::direxist(const char *path)
{
  struct stat sb;

  return (stat(path, &sb) == 0);
}

#endif

int	main(int ac, char **av)
{
  std::cout << std::boolalpha << Mkdir::direxist("plop") << std::endl;
  Mkdir::mkdir("plop");
  return (0);
}
