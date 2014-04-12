//
// FileFStream.hh for FileFStream.hh in /home/bequig_s//workspace/c++/babel/DataBase
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Thu May 30 19:20:37 2013 sebastien bequignon
// Last update Sat Jun  1 18:46:06 2013 sebastien bequignon
//

#ifndef FILEFSTREAM_H_
# define FILEFSTREAM_H_

#include <fstream>
#include <string>
#include <stdint.h>
#include "IFile.hh"

class File : public std::fstream, public IFile
{
private:
  std::string lastfile;

public:
  class Mkdir
  {
  public:
    static bool mkdir(const char *path);
    static bool direxist(const char *path);
  };

  File();
  File(std::string const &name);
  ~File();
  bool openFile(std::string const &name);
  bool openOCreate(std::string const &name);
  void reset();
  void toEnd();
  bool is_open() const;
  bool eof() const;
  bool good() const;
  void write(const char *val, uint64_t size);
  void read(char *val, uint64_t size);
  void close();
  uint64_t size() const;
};

template <typename T>
File &operator<<(File &file, T &val)
{
  static_cast<std::fstream &>(file) << val;
  return (file);
}

template <typename T>
File &operator>>(File &file, T &val)
{
  static_cast<std::fstream &>(file) >> val;
  return (file);
}

#endif /* !FILEFSTREAM_H_ */
