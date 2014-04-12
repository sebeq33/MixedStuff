//
// GomokuRules.cpp for GomokuRules.cpp in /home/bequig_s//workspace/ia/gomoku
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Thu Jun  6 16:41:42 2013 sebastien bequignon
// Last update Mon Jun 17 18:44:37 2013 sebastien bequignon
//

#include "GomokuRules.hh"

Gomoku::GomokuRules::GomokuRules(uint8_t val)
  : rules(val)
{

}

Gomoku::GomokuRules::~GomokuRules()
{

}

void Gomoku::GomokuRules::enableRule(uint8_t rule)
{
  rules |= rule;
}

void Gomoku::GomokuRules::disableRule(uint8_t rule)
{
  rules &= ~rule;
}

void Gomoku::GomokuRules::toggleRule(uint8_t rule)
{
  rules ^= rule;
}

bool Gomoku::GomokuRules::isSet(uint8_t rule) const
{
  return (((rules & rule) ^ rule) == 0);
}

bool Gomoku::GomokuRules::operator==(uint8_t rule) const
{
  return (this->isSet(rule));
}
