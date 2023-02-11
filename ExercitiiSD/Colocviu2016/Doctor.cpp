#include "Doctor.h"
#include "Copil.h"
#include "Pacient40.h"
void Doctor::print(std::ostream& os)const {
          os << "Pacientii sunt: " << std::endl;
          for (auto pac : pacienti)
                    pac->print(os);
};
void Doctor::addPacient() {
          int k;
          std::shared_ptr<Pacient> aux;
          std::cout << "In ce catogorie de varsta se incadreaza pacientul?\n1.0-18 ani Copil\n2.Adult <40 ani\n 3.Adult>40 ani" << std::endl;
          std::cin >> k;
          if (k == 1) aux = std::make_shared<CopilClass>();
          else if (k == 2) aux = std::make_shared<Pacient>();
          else if (k == 3) aux = std::make_shared<Pacient40>();
          else throw "Nu exista acest tip";
          aux->read(std::cin);
          pacienti.push_back(aux);
};
void Doctor::read(std::istream& is) {
          int i, k;
          std::cout << "Cati pacienti vreti sa adaugati?" << std::endl;
          is >> i;

          std::shared_ptr<Pacient> aux;
          for (int j = 0;j < i;j++) {
                    std::cout << "In ce catogorie de varsta se incadreaza pacientul?\n1.0-18 ani Copil\n2.Adult <40 ani\n 3.Adult>40 ani" << std::endl;
                    is >> k;
                    if (k == 1) aux = std::make_shared<CopilClass>();
                    else if (k == 2) aux = std::make_shared<Pacient>();
                    else if (k == 3) aux = std::make_shared<Pacient40>();
                    else throw "Nu exista acest tip";
                    aux->read(std::cin);
                    pacienti.push_back(aux);
          }
};
void Doctor::searchByName(std::string name) const {
          for (auto pac : pacienti)
                    pac->searchByName(name);
};
void Doctor::searchChild()const {
          for (auto i : pacienti)
                    if (i->getType() == PacientType::Copil) i->risc();
};
void Doctor::searchAdult() const {
          for (auto i : pacienti)
                    if (i->getType() == PacientType::Adult) i->risc();
};