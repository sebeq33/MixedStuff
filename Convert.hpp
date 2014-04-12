#ifndef CONVERT_HPP_
# define CONVERT_HPP_

#include <string>
#include <sstream>

template<typename T, typename U = std::string const &>
class Convert
{
public:

  static T convert(U text)
  {
    T value;
    std::stringstream ss;
    ss << text;
    ss >> value;
    return (value);
  }
};

#endif /* !CONVERT_H_ */
