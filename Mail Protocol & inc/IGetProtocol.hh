//
// IGetProtocol.hh for IGetProtocol.hh in /home/bequig_s//workspace/rush/bmail
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Sun Mar 10 21:10:15 2013 sebastien bequignon
// Last update Sun Mar 10 21:12:08 2013 sebastien bequignon
//

#ifndef IGETPROTOCOL_H_
# define IGETPROTOCOL_H_

#include "Message.hh"

class IGetProtocol
{
public:
  virtual ~IGetProtocol() {}
  virtual Message *getMail(int idMail) = 0;
  virtual int getNbMail() = 0;
  virtual void suprMail(int idMail) = 0;
};

#endif /* !IGETPROTOCOL_H_ */
