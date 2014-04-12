//
// Pattern.cpp for Pattern.cpp in /home/bequig_s//workspace/ia/gomoku
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Fri Jun  7 21:27:30 2013 sebastien bequignon
// Last update Tue Jun 25 16:00:11 2013 sebastien bequignon
//

#include "Pattern.hh"

Pattern::Pattern(uint32_t value, uint8_t size)
  : val(value), size(size)
{
}

Pattern::~Pattern()
{

}

Gomoku::Symbol Pattern::operator[](uint8_t index) const
{
  return (this->getValue(index));
}

Gomoku::Symbol Pattern::getValue(uint8_t index) const
{
  return (static_cast<Gomoku::Symbol>((this->val >> index) & 3));
}

void Pattern::setValues(uint32_t val, uint8_t size)
{
  this->val = val;
  this->size = size;
}

void Pattern::setValue(uint8_t index, Gomoku::Symbol val)
{
  this->val &= (~0 & (3 << index));
  this->val |= (val << index);
}

void Pattern::setValue(uint32_t val)
{
  this->val = val;
}

uint32_t Pattern::getValue() const
{
  return (val);
}

void Pattern::setSize(uint8_t size)
{
  this->size = size;
}

bool Pattern::match(uint32_t oval) const
{
  return ((val ^ oval) == 0);
}

bool Pattern::match(uint32_t oval, uint32_t mask) const
{
  return (((val & mask) ^ oval) == 0);
}

bool Pattern::match(Pattern &other, uint32_t mask) const
{
  return (this->match(other.val, mask));
}

bool Pattern::match(const Pattern &other) const
{
  return (this->match(other.val));
}

bool Pattern::operator==(const Pattern &other) const
{
  return (this->match(other.val));
}

bool Pattern::operator==(uint32_t value) const
{
  return (this->match(value));
}

Pattern& Pattern::operator=(uint32_t oval)
{
  this->val = oval;
  return (*this);
}

Pattern& Pattern::operator=(const Pattern &other)
{
  this->val = other.val;
  this->size = other.size;
  return (*this);
}

Pattern& Pattern::operator<<(Gomoku::Symbol symb)
{
  this->val = (this->val << 2) | symb;
  return (*this);
}

Pattern& Pattern::operator<<=(uint8_t decal)
{
  this->val <<= decal;
  return (*this);
}

Pattern& Pattern::operator>>=(uint8_t decal)
{
  this->val >>= decal;
  return (*this);
}

uint8_t Pattern::getSize() const
{
  return (this->size);
}

uint32_t Pattern::getSizeMask() const
{
  return (~(~0 << (this->size << 2))); // (size * 2) bit at 1, rest at 0
}

void	Pattern::dump(std::ostream &stream) const
{
  const uint32_t cleanVal = val;
  const char *bytes = reinterpret_cast<const char *> (&cleanVal);
  int8_t nbbytes = 2;
  int8_t i;

  while (nbbytes >= 0)
    {
      i = 7;
      while (i >= 0)
	{
	  stream << static_cast<char>(((((bytes[nbbytes]) >> i) & 1) + '0'));
	  i--;
	}
      if (nbbytes > 0)
	stream << '.';
      nbbytes--;
    }
}

std::ostream &operator<<(std::ostream &stream, const Pattern &val)
{
  val.dump(stream);
  return (stream);
}
