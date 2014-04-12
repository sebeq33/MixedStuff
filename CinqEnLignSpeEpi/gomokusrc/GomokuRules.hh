//
// GomokuRules.hh for GomokuRules.hh in /home/bequig_s//workspace/ia/gomoku
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Thu Jun  6 16:38:18 2013 sebastien bequignon
// Last update Mon Jun 17 17:21:50 2013 sebastien bequignon
//

#ifndef GOMOKURULES_H_
# define GOMOKURULES_H_

#include <stdint.h>

namespace Gomoku
{
  class GomokuRules
  {
  private:
    uint8_t rules;

  public:
    GomokuRules(uint8_t val = 0);
    ~GomokuRules();
    void enableRule(uint8_t rule);
    void disableRule(uint8_t rule);
    void toggleRule(uint8_t rule);
    bool isSet(uint8_t rule) const;
    bool operator==(uint8_t rule) const;
  };
}

#endif /* !GOMOKURULES_H_ */
