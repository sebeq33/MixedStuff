//
// circ_buff.cpp for circ_buff.cpp in /home/bequig_s//workspace/test_perso/circular_buffer
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Fri Jul 26 14:44:58 2013 sebastien bequignon
// Last update Fri Jul 26 23:05:12 2013 sebastien bequignon
//

#include "CircBuff.hh"

CircBuff::CircBuff(uint32_t size)
  : read(0), write(0), current_size(0), max_size(size), override(false)
{
  buff = new char[size];
}

CircBuff::CircBuff(const CircBuff& other)
{
  if (other.buff)
    {
      this->free();
      this->buff = new char[other.max_size];
      this->read = 0;
      this->write = other.current_size;
      this->current_size = other.current_size;
      this->max_size = other.max_size;

      uint32_t i = 0;
      uint32_t pos = other.read;
      while (i < this->current_size)
	{
	  this->buff[i++] = other.buff[pos++];
	  if (pos >= other.max_size)
	    pos = 0;
	}
    }
}

CircBuff::~CircBuff()
{
  this->free();
}

CircBuff &CircBuff::operator=(const CircBuff &other)
{
  if (&other != this && other.buff)
    {
      this->free();
      this->buff = new char[other.max_size];
      this->read = 0;
      this->write = other.current_size;
      this->current_size = other.current_size;
      this->max_size = other.max_size;

      uint32_t i = 0;
      uint32_t pos = other.read;
      while (i < this->current_size)
	{
	  this->buff[i++] = other.buff[pos++];
	  if (pos >= other.max_size)
	    pos = 0;
	}
    }
  return (*this);
}

bool		CircBuff::fill(const char *data, uint32_t size)
{
  uint32_t	i;

  if (!override && current_size + size >= max_size)
    return (false);
  i = 0;
  while (i < size)
    {
      this->buff[write++] = data[i++];
      if (this->write >= this->max_size)
	this->write = 0;
    }
  if (current_size + size >= max_size)
    {
      current_size = max_size;
      read = write;
    }
  else
    current_size += size;
  return (true);
}

int32_t		CircBuff::fill(Readable &r, int32_t size)
{
  int32_t	ret;
  uint32_t	toRead;
  uint32_t	total;

  if ((!override && current_size + size >= max_size) || size > max_size)
    return (-2);
  total = 0;
  while (total < size)
    {
      toRead = (write + size) % max_size;
      if (toRead > size - total)
	toRead = size - total;
      if (!(ret = r.read(&buff[write], toRead)))
	{
	  if (total == 0)
	    return (-1);
	  else
	    break ;
	}
      write += ret;
      total += ret;
      if (write >= max_size)
	write = 0;
      if (ret < toRead)
	break ;
    }
  if (current_size + total >= max_size)
    {
      current_size = max_size;
      read = write;
    }
  else
    current_size += total;
  return (total);
}

uint32_t CircBuff::get(char *data, uint32_t size)
{
  uint32_t	i;

  if (size > current_size)
    size = current_size;
  i = 0;
  while (i < size)
    {
      data[i++] = buff[read++];
      current_size--;
      if (read >= max_size)
	read = 0;
    }
  return (size);

}

uint32_t CircBuff::getline(char *data, uint32_t limit)
{
  uint32_t	i;

  if (current_size == 0)
    return (0);
  i = 0;
  while (i < limit)
    {
      data[i] = buff[read++];
      current_size--;
      if (read >= max_size)
	read = 0;
      if (current_size == 0 || data[i] == '\n' || data[i] == '\0')
	return (i + 1);
      i++;
    }
  return (limit);
}

bool CircBuff::isFull() const
{
  return (current_size == max_size);
}

bool CircBuff::overridable() const
{
  return (this->override);
}

void CircBuff::setOverride(bool override)
{
  this->override = override;
}

uint32_t CircBuff::getSize() const
{
  return (buff ? current_size : 0);
}

void CircBuff::free()
{
  if (this->buff)
    {
      delete[] this->buff;
      this->buff = NULL;
    }
}
