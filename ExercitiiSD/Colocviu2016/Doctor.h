#ifndef DOCTOR
#define DOCTOR

#include <iostream>
#include <memory>
#include <vector>
#include "Pacient.h"
#include "PrintRead.h"
class Doctor:public PrintRead {
          std::vector < std::shared_ptr <Pacient>> pacienti;
public:
          Doctor(std::vector < std::shared_ptr <Pacient>> pacienti = {}):pacienti(pacienti) {};
          void print(std::ostream&)const override;
          void read(std::istream&) override;
          void searchByName(std::string) const;
          void addPacient();
          void searchChild()const;
          void searchAdult() const;
};
#endif