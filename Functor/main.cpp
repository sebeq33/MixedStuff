#include <string>
 #include "Function.hpp"
 
class Name
{
public:
  Name(){}
 
   char  operator()(char c1)
   {
     return c1;
   }
 
   virtual ~Name(){}
 };
 
 int funct()
 {
   return 54;
 }
 
 
 int funct1(char c)
 {
   std::cout << c << std::endl;
   return 0;
 }
 
 int main()
 {
   Function<int (char)> f = &funct1;
   Function<int (char)> b = boost::bind(&funct1, _1);
    Name n;
   Function<char (char)> c = n;
 
  f('f');
   b('b');
  std::cout << c('o') << std::endl;
   return 0;
 }