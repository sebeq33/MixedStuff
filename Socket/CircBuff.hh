//
// circ_buff.hh for circ_buff.hh in /home/bequig_s//workspace/test_perso/circular_buffer
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Fri Jul 26 14:45:05 2013 sebastien bequignon
// Last update Fri Jul 26 23:10:09 2013 sebastien bequignon
//

#ifndef CIRC_BUFF_H_
# define CIRC_BUFF_H_

#include <stdint.h>
#include <stddef.h>
#include <unistd.h>

class Readable
{
public:
  virtual ~Readable() {};
  virtual int32_t read(char *data, int32_t size);
};

class CircBuff
{
private:
  char *buff;

  uint32_t read;
  uint32_t write;
  uint32_t current_size;
  uint32_t max_size;

  bool override : 1;

public:
  CircBuff(uint32_t size = 4096);
  CircBuff(const CircBuff& other);
  ~CircBuff();
  CircBuff &operator=(const CircBuff &other);

  bool fill(const char *data, uint32_t size);
  int32_t fill(Readable &r, int32_t size);
  uint32_t get(char *data, uint32_t size);
  uint32_t getline(char *data, uint32_t limit = 4096);

  bool isFull() const;
  bool overridable() const;
  void setOverride(bool override = true);
  uint32_t getSize() const;
  void free();

  template <typename T>
  CircBuff &operator<<(T &val)
  {
    this->fill(reinterpret_cast<char *>(&val), sizeof(val));
    return (*this);
  }

  template <typename T>
  CircBuff &operator>>(T &val)
  {
    this->get(reinterpret_cast<char *>(&val), sizeof(val));
    return (*this);
  }

};

#endif /* !CIRC_BUFF_H_ */
