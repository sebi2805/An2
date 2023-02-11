#include <iostream>
#include "Moderne.h"
Moderne::Moderne(Moderne &obj) : Electronice(obj), Educative(obj)
{
          brand = obj.brand;
};
void Moderne::print(std::ostream &os) const
{
          BToy::print(os);
          Electronice::printSubClass(os);
          Educative::printSubClass(os);
          os << " Brandul este " << brand << std::endl;
};
void Moderne::read(std::istream &is)
{
          BToy::read(is);
          Electronice::readSubClass(is);
          Educative::readSubClass(is);
          std::cout << "Care este brandul? " << std::endl;
          is >> brand;
};
std::ostream &operator<<(std::ostream &os, Moderne &obj)
{
          obj.print(os);
          return os;
};
std::istream &operator>>(std::istream &is, Moderne &obj)
{
          obj.read(is);
          return is;
};