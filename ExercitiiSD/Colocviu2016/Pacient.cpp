#include "Pacient.h"
void Pacient::print(std::ostream& os) const {
          os << "Numele pacientului este " << nume << " prenumele pacientului este " << prenume << " varsta pacientului este " << varsta <<
                    " adresa pacientului este " << adresa << ". (" << ziT << "." << lunaT << "." << anT << ")" << " tensiunea arteriala este "
                    << tensiune << ". (" << ziC << "." << lunaC << "." << anC << ")" << " colesterolulul este " << valoareColesterol;
          if (valoareColesterol < 200)
                    os << " colesterol care este optim";
          else
                    if (valoareColesterol >= 200 && valoareColesterol <= 239)
                              os << " colesterol care este normmal";
                    else     if (valoareColesterol > 239)
                              os << " colesterol care este crescut";
          os << std::endl;
};
void Pacient::read(std::istream& is) {
          std::cout << "Care este numele pacientului" << std::endl;
          is >> nume;
          std::cout << "Care este prenumele pacientului" << std::endl;
          is >> prenume;
          std::cout << "Care este varsta pacientului" << std::endl;
          is >> varsta;
          std::cout << "Care este adresa pacientului" << std::endl;
          is >> adresa;
          std::cout << "Care este tensiune pacientului" << std::endl;
          is >> tensiune;

          std::cout << "Care este ziua  " << std::endl;
          is >> ziT;
          std::cout << "Care este lune pacientului" << std::endl;
          is >> lunaT;
          std::cout << "Care este anul pacientului" << std::endl;
          is >> anT;
          std::cout << "Care este valoarea colesterolului pacientului" << std::endl;
          is >> valoareColesterol;
          std::cout << "Care este ziua  " << std::endl;
          is >> ziC;
          std::cout << "Care este lune pacientului" << std::endl;
          is >> lunaC;
          std::cout << "Care este anul pacientului" << std::endl;
          is >> anC;

};

int Pacient::idClass = 0;
void Pacient::searchByName(std::string& _name) {
          if (nume == _name) this->print(std::cout);
};
bool Pacient::risc() const {
          if (tensiune > 139) { print(std::cout); return true; }
          else if (valoareColesterol > 239) { print(std::cout); return true; }
          return false;
};
PacientType Pacient::getType()const {
          return type;
}
Pacient::Pacient(Pacient& obj) {
          nume = obj.nume;
          prenume = obj.prenume;
          adresa = obj.adresa;
          tensiune = obj.tensiune;
          valoareColesterol = obj.valoareColesterol;
          ziC = obj.ziC;
          ziT = obj.ziT;
          lunaC = obj.lunaC;
          lunaT = obj.lunaT;
          anC = obj.anC;
          anT = obj.anT;
          varsta = obj.varsta;
          type = obj.type;
          id = obj.id;
};

std::ostream& operator <<(std::ostream& os, const Pacient& obj) {
          obj.print(os);
};
std::istream& operator >>(std::istream& is,
          Pacient& obj) {
          obj.read(is);
};