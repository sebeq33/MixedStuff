//
// Net.cpp for Rush3 in /home/savide_k/local/piscine_cpp/Rush3/piscine_cpp_rush3-2016-bequig_s
//
// Made by kevin savidetove
// Login   <savide_k@epitech.net>
//
// Started on  Sun Jan 27 00:10:39 2013 kevin savidetove
// Last update Sun Jan 27 07:08:27 2013 sebastien bequignon
//

#include "Net.hh"

Net::Net() : _dataRecieved(0),  _dataTransmitted(0) {}

Net::~Net() {}

int Net::my_atoi(std::string str)
{
  return (atoi(str.substr(0, str.find(' ')).c_str()));
}

static std::string getDataInLine(std::string a_line, int n, bool flag)
{
  char *pos = const_cast<char *>(a_line.c_str());
  char *end;
  std::string return_value;

  if (flag)
    while (*pos && *pos != ':')
      ++pos;
  for (int i = 0; i < n; i++)
    {
      while (*pos != '\0' && *pos != ' ' && *pos != '\t')
	++pos;
      while (*pos != '\0' && (*pos == ' ' || *pos == '\t'))
	++pos;
    }
  for (end = pos; *end != '\0' && *end != ' ' && *end != '\t'; end++);
  return_value = std::string(pos, end);
  return (return_value);
}

void Net::updateData()
{
  std::ifstream file;
  std::string	a_line;

  file.open("/proc/net/netstat");
  if (file.is_open())
    {
      _prevDataRecieved = _dataRecieved;
      _prevDataTransmitted = _dataTransmitted;
      for (int i = 0; i < 4 ; i++)
	getline(file, a_line);
      _dataRecieved = my_atoi(getDataInLine(a_line, 7, true));
      _dataTransmitted = my_atoi(getDataInLine(a_line, 8, true));

      _receptionRate = (_dataRecieved - _prevDataRecieved) / 0.5;
      _transmissionRate = (_dataTransmitted - _prevDataTransmitted) / 0.5;
    }
}
int	Net::getDataReceived() const
{
  return (_dataRecieved);
}

int	Net::getDataTransmitted() const
{
  return (_dataTransmitted);
}

int	Net::getReceptionRate() const
{
  return (_receptionRate);
}

int	Net::getTransmissionRate() const
{
  return (_transmissionRate);
}

TypeModule Net::getType() const
{
  return (NET);
}
