//
// Pattern.cpp for Pattern.cpp in /home/bequig_s//workspace/ia/gomoku
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Fri Jun  7 21:27:30 2013 sebastien bequignon
// Last update Thu Jun 13 16:41:42 2013 sebastien bequignon
//

#include "Pattern.hh"

Pattern::Pattern(uint32_t value, uint8_t siz)
  : val(value), size(siz)
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

bool Pattern::match(uint32_t oval) const
{
  return ((val ^ oval) == 0);
}

bool Pattern::match(uint32_t oval, uint32_t mask) const
{
  // Pattern res(val & mask);
  // Pattern check(mask);

  // std::cout << res << " << res" << std::endl;
  // std::cout << check << " << mask" << std::endl;
  return (((val & mask) ^ oval) == 0);

  // uint32_t first  = size ? (val & ~(~0 << size))  : val;
  // uint32_t second = osize ? (oval & ~(~0 << osize)) : oval;

  // Pattern pattern(first);
  // Pattern check(second);

  // std::cout << std::endl;
  // std::cout << std::endl;
  // std::cout << "pattern = " << pattern << std::endl;
  // std::cout << "check   = " << check   << std::endl;
  // std::cout << "size    = " << (int) size  << std::endl;
  // std::cout << "osize   = " << (int) osize << std::endl;

  // return ((first ^ second) == 0);

  // if (size)
  //   {
  //     uint32_t mask = ~(~0 << size);
  //     return (((val & mask) ^ (oval & mask)) == 0);
  //   }
  // return ((val ^ oval) == 0);
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
  if (this->size != 0)
    return (this->size);

  uint8_t res = 0;
  uint8_t tmp = this->val;

  for (uint8_t i = 0; i < 16; ++i)
    {
      if (this->val & 1 != 0)
	res = i;
      tmp >>= 1;
    }
  return (res);
}

uint32_t Pattern::getSizeMask() const
{
  return (~(~0 << this->getSize()));
}

void	Pattern::dump(std::ostream &stream) const
{
  uint32_t cleanVal = val;
  const char *bytes = reinterpret_cast<const char *> (&cleanVal);
  uint8_t size = 3;
  int8_t i;

  while (size > 0)
    {
      i = 7;
      while (i >= 0)
	{
	  stream << static_cast<char>(((((bytes[size - 1]) >> i) & 1) + '0'));
	  i--;
	}
      if (--size > 0)
	stream << ' ';
    }
}

std::ostream &operator<<(std::ostream &stream, const Pattern &val)
{
  val.dump(stream);
  return (stream);
}
