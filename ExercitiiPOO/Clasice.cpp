#include <iostream>
#include "Clasice.h"
Clasice::Clasice(Clasice &obj) : BToy(obj)
{
          material = obj.material;
          culoare = obj.culoare;
};
void Clasice::print(std::ostream &os) const
{
          BToy::print(os);
          os << " Materialul este: " << material << " culoare este " << std::endl;
};
void Clasice::read(std::istream &is)
{
          BToy::read(is);
          std::cout << "Care este materialul?" << std::endl;
          is >> material;
          std::cout << "Care este culoare?" << std::endl;
          is >> culoare;
};
std::ostream &operator<<(std::ostream &os, Clasice &obj)
{
          obj.print(os);

          return os;
};
std::istream &operator>>(std::istream &is, Clasice &obj)
{
          obj.read(is);
          return is;
};