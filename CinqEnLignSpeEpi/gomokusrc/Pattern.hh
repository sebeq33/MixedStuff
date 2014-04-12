//
// Pattern.hh for Pattern.hh in /home/bequig_s//workspace/ia/gomoku
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Fri Jun  7 17:36:39 2013 sebastien bequignon
// Last update Mon Jun 24 14:11:16 2013 sebastien bequignon
//

#ifndef PATTERN_H_
# define PATTERN_H_

#include <iostream>
#include <stdint.h>
#include "GomokuEnum.hh"

class Pattern
{
private:
  uint32_t val : 24;
  uint8_t  size : 4;

public:
  Pattern(uint32_t val = 0, uint8_t size = 0);
  ~Pattern();

  Gomoku::Symbol operator[](uint8_t index) const;
  Gomoku::Symbol getValue(uint8_t index) const;
  uint32_t getValue() const;

  void setValues(uint32_t val, uint8_t size);
  void setValue(uint8_t index, Gomoku::Symbol val);
  void setValue(uint32_t val);
  void setSize(uint8_t size);

  bool match(uint32_t oval) const;
  bool match(uint32_t oval, uint32_t mask) const;
  bool match(const Pattern &other) const;
  bool match(Pattern &other, uint32_t mask) const;
  bool operator==(const Pattern &other) const;
  bool operator==(uint32_t value) const;

  Pattern& operator=(uint32_t oval);
  Pattern& operator=(const Pattern &oval);

  Pattern& operator<<(Gomoku::Symbol symb);
  Pattern& operator<<=(uint8_t decal);
  Pattern& operator>>=(uint8_t decal);

  uint8_t	getSize() const;
  uint32_t	getSizeMask() const;
  void		dump(std::ostream & stream = std::cout) const;
};

std::ostream &operator<<(std::ostream &stream, const Pattern &val);

#endif /* !PATTERN_H_ */
