#include "Copil.h"
void CopilClass::print(std::ostream& os) const {
          Pacient::print(os);
          os << " numele si prenumele tatalui sunt " << numeT << " " << prenumeT << " numele si prenumele mamei sunt "
                    << numeM << " " << prenumeM << " nivelul proteinei este de " << proteina << std::endl;
};
void CopilClass::read(std::istream& is) {
          Pacient::read(is);
          std::cout << "Care este numele tatalui?" << std::endl;
          is >> numeT;
          std::cout << "Care este prenumele tatalui?" << std::endl;
          is >> prenumeT;
          std::cout << "Care este numele mamei?" << std::endl;
          is >> numeM;
          std::cout << "Care este prenumele mamei?" << std::endl;
          is >> prenumeM;
          std::cout << "Care este nivelul proteinei?" << std::endl;
          is >> proteina;

};
bool CopilClass::risc() const {
          if (Pacient::risc()) return true;
          if (antecedente != "undefined")
                    print(std::cout);
};
CopilClass::CopilClass(CopilClass& obj):Pacient(obj) {
          numeM = obj.numeM;
          prenumeM = obj.prenumeM;
          numeT = obj.numeT;
          prenumeT = obj.prenumeT;
          zi = obj.zi;
          luna = obj.luna;
          an = obj.an;
          proteina = obj.proteina;

};
std::ostream& operator <<(std::ostream& os, const CopilClass& obj) {
          obj.print(os);
};
std::istream& operator >>(std::istream& is,
          CopilClass& obj) {
          obj.read(is);
};