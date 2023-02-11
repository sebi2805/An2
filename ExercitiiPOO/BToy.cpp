
#include <iostream>
#include "BToy.h"
int BToy::numarJucarii = 0;
int BToy::numarClasice = 0;
int BToy::numarModerne = 0;
int BToy::numarElectronice = 0;
int BToy::numarEducative = 0;
BToy::BToy(BToy &obj)
{

          tip = obj.tip;
          denumire = obj.denumire;
          dimensiune = obj.dimensiune;
};
void BToy::print(std::ostream &os) const
{
          os << "Denumire este " << denumire << " dimensiunea este " << dimensiune << " tipul este " << tip << std::endl;
};
void BToy::read(std::istream &is)
{
          std::cout << "Care este denumirea?" << std::endl;
          is >> denumire;
          std::cout << "Care este dimensiunea?" << std::endl;
          is >> dimensiune;
          std::cout << "Care este tipul?" << std::endl;
          is >> tip;
};
std::ostream &operator<<(std::ostream &os, BToy &obj)
{
          obj.print(os);
          return os;
};
std::istream &operator>>(std::istream &is, BToy &obj)
{
          obj.read(is);
          return is;
};
const std::string BToy::getDenumire() const
{
          return denumire;
};
const std::string BToy::getTip() const
{
          return tip;
};