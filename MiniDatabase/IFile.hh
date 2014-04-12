//
// IFile.hh for IFile.hh in /home/bequig_s//workspace/c++/babel/DataBase
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Thu May 30 15:00:12 2013 sebastien bequignon
// Last update Thu May 30 22:58:49 2013 sebastien bequignon
//

#ifndef IFILE_H_
# define IFILE_H_

#include <string>
#include <stdint.h>

class IFile
{
public:
  virtual ~IFile() {};
  virtual bool openFile(const std::string &filename) = 0;
  virtual bool openOCreate(const std::string &filename) = 0;
  virtual void reset() = 0;
  virtual void toEnd() = 0;
  virtual void write(const char *val, uint64_t size) = 0;
  virtual void read(char *val, uint64_t size) = 0;
  virtual bool is_open() const = 0;
  virtual bool eof() const = 0;
  virtual bool good() const = 0;
  virtual void close() = 0;
  virtual uint64_t size() const = 0;
};

#endif /* !IFILE_H_ */
