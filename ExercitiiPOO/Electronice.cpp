#include <iostream>
#include "Electronice.h"
Electronice::Electronice(Electronice &obj) : BToy(obj)
{
          numarBaterii = obj.numarBaterii;
};
void Electronice::print(std::ostream &os) const
{
          BToy::print(os);
          printSubClass(os);
};
void Electronice::read(std::istream &is)
{
          BToy::read(is);
          readSubClass(is);
};
std::ostream &operator<<(std::ostream &os, Electronice &obj)
{
          obj.print(os);
          return os;
};
std::istream &operator>>(std::istream &is, Electronice &obj)
{
          obj.read(is);
          return is;
};
void Electronice::readSubClass(std::istream &is)
{
          std::cout << "Care este numarul de baterii? " << std::endl;
          is >> numarBaterii;
};
void Electronice::printSubClass(std::ostream &os) const
{
          os << " Abilitatea numarul de baterii: " << numarBaterii << std::endl;
};