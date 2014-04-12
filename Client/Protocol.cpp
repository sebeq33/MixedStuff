#include "ClientProtocol.hh"

std::map<int8_t, Protocol::funcPtr>	Protocol::_binProtocol;

Protocol::Protocol()
{
  if (Protocol::_binProtocol.empty())
  {
    Protocol::_binProtocol[3] = &Protocol::createConfirmation;
  }
}

Protocol::~Protocol()
{
}

int32_t Protocol::executeRequest(char *buf)
{
  try
  {
    std::cout << std::endl;
    std::cout << "[LOG] Receveiving request number " << (int) buf[0] << std::endl;
    return ((this->*_binProtocol.at(buf[0]))(buf));
  }
  catch (std::out_of_range const& oor)
  {
    (void) oor;
    std::cerr << "[ERROR] Bad request (ID = " << (int) buf[0] << "). Request rejected." << std::endl;
    return (-1);
  }
}

int32_t Protocol::createConfirmation(char *buf)
{
  std::cout << "create confirmation" << std::endl;
}
