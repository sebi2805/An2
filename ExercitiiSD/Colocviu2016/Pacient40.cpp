
#include "Pacient.h"
#include "Pacient40.h"
void Pacient40::print(std::ostream& os) const {
          Pacient::print(os);
          os << "Acest pacient ";
          if (fum) os << "nu";
          os << " este fumator si nivelul de sedentarism este ";
          if (sed == Sedentarism::scazut)
                    os << " scazut";
          if (sed == Sedentarism::mediu)
                    os << " mediu";
          if (sed == Sedentarism::ridicat)
                    os << " ridicat";
          os << std::endl;
};
void Pacient40::read(std::istream& is) {
          Pacient::read(is);
          std::cout << "Este fumator\n1.Da\n2.Nu" << std::endl;
          int i;
          is >> i;
          if (i)
                    fum = true;
          else fum = false;

          std::cout << "Este sedentar? \n1.Scazut\n2.Mediu\3.Ridicat" << std::endl;
          is >> i;
          if (i == 1)
                    sed = Sedentarism::scazut;
          else  if (i == 2)
                    sed = Sedentarism::mediu;
          else if (i == 3)
                    sed = Sedentarism::ridicat;         else
                    throw "Nu exista";

};
void Pacient40::setSed(Sedentarism obj) {
          sed = obj;
};
void Pacient40::setFum(bool obj) {
          fum = obj;
};
bool Pacient40::risc() const {
          if (Pacient::risc()) return true;
          if (fum) print(std::cout);
          else if (sed == Sedentarism::ridicat) print(std::cout);
};
Pacient40::Pacient40(Pacient40& obj):Pacient(obj) {
          fum = obj.fum;
          sed = obj.sed;
};
std::ostream& operator <<(std::ostream& os, const Pacient40& obj) {
          obj.print(os);
};
std::istream& operator >>(std::istream& is,
          Pacient40& obj) {
          obj.read(is);
};