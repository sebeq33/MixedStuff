//
// File.cpp for File.cpp in /home/bequig_s//workspace/c++/babel/DataBase
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Thu May 30 19:23:42 2013 sebastien bequignon
// Last update Sat Jun  1 18:47:55 2013 sebastien bequignon
//

#include <exception>
#include "DataBase/File.hh"

File::File()
{
}

File::File(std::string const &name)
{
  if (!openFile(name))
    throw std::exception();
}

File::~File()
{

}

bool File::openFile(std::string const &name)
{
  const char		*str = name.c_str();

  if (this->is_open())
    {
	if (lastfile == name)
	  {
	    this->reset();
	    return (true);
	  }
	else
	  this->close();
    }
  this->open(str,
	     std::fstream::in |
	     std::fstream::out |
	     std::fstream::binary);
  lastfile = name;
  return (this->is_open());
}

bool File::openOCreate(std::string const &name)
{
  if (!openFile(name))
    {
      const char	*str = name.c_str();
      this->open(str,
		 std::fstream::in |
		 std::fstream::out |
		 std::fstream::binary |
		 std::fstream::trunc);
    }
  return (this->is_open());
}

#include <iostream>

void File::reset()
{
  if (this->is_open())
    {
      this->clear();
      this->seekg(0, this->beg);
    }
}

void File::toEnd()
{
  if (this->is_open())
    this->seekg(0, this->end);
}

bool File::is_open() const
{
  return (this->std::fstream::is_open());
}

bool File::eof() const
{
  return (this->std::fstream::eof());
}

bool File::good() const
{
  return (this->std::fstream::good());
}

void File::write(const char *val, uint64_t size)
{
  this->std::fstream::write(val, size);
}

void File::read(char *val, uint64_t size)
{
  this->std::fstream::read(val, size);
}

void File::close()
{
  this->std::fstream::close();
}

uint64_t File::size() const
{
  if (!this->good())
    return (0);

  uint64_t res;

  try
    {
      std::streambuf* pbuf = this->rdbuf();
      std::streamsize size = pbuf->in_avail();
      res = size;
    }
  catch (std::exception &ex)
    {
      (void) ex;
      res = 0;
    }
  return (res);
}

#ifdef WIN32
#include <direct.h>
#include <Windows.h>

bool File::Mkdir::mkdir(const char *path)
{
  return (_mkdir(path) == 0);
}

bool File::Mkdir::direxist(const char *path)
{
  DWORD attr = GetFileAttributesA(path);
  return (attr != INVALID_FILE_ATTRIBUTES && attr & FILE_ATTRIBUTE_DIRECTORY);
}

#else
#include <sys/types.h>
#include <sys/stat.h>

bool File::Mkdir::mkdir(const char *path)
{
  return (::mkdir(path, 0700) == 0);
}

bool File::Mkdir::direxist(const char *path)
{
  struct stat sb;

  return (stat(path, &sb) == 0);
}

#endif
