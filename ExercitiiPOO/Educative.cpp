#include <iostream>
#include "Educative.h"
Educative::Educative(Educative &obj) : BToy(obj)
{
          abilitatea = obj.abilitatea;
};
void Educative::print(std::ostream &os) const
{
          BToy::print(os);
          printSubClass(os);
};
void Educative::read(std::istream &is)
{
          BToy::read(is);
          readSubClass(is);
};
std::ostream &operator<<(std::ostream &os, Educative &obj)
{
          obj.print(os);
          return os;
};
std::istream &operator>>(std::istream &is, Educative &obj)
{
          obj.read(is);
          return is;
};
void Educative::readSubClass(std::istream &is)
{
          std::cout << "Care este abilitatea dezvoltata? " << std::endl;
          is >> abilitatea;
};
void Educative::printSubClass(std::ostream &os) const
{
          os << " Abilitatea este: " << abilitatea << std::endl;
};