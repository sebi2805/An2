#ifndef PACIENT
#define PACIENT
#include <iostream>
#include "PrintRead.h"
enum PacientType {
          Copil, Adult, Unknown
};
class Pacient:virtual public PrintRead {
          std::string nume, prenume, adresa;
          int valoareColesterol, tensiune, varsta;
          int ziC, lunaC, anC, ziT, lunaT, anT;
          static int idClass;
          int id;
          PacientType type;
public:
          void print(std::ostream&) const override;
          void read(std::istream&) override;
          virtual bool risc() const;
          Pacient(Pacient&);
          PacientType getType() const;
          void searchByName(std::string&);
          Pacient(PacientType type = PacientType::Unknown, std::string nume = "undefined", std::string prenume = "undefined",
                    std::string adresa = "undefined", int valoareColesterol = 0, int tensiune = 0, int varsta = 0,
                    int ziC = 0, int lunaC = 0, int anC = 0, int ziT = 0, int lunaT = 0, int anT = 0):nume(nume), type(type),
                    prenume(prenume), adresa(adresa),
                    valoareColesterol(valoareColesterol), varsta(varsta), tensiune(tensiune) {
                    idClass++;
                    id = id;
          };
          friend std::ostream& operator <<(std::ostream&, const Pacient&);
          friend std::istream& operator >>(std::istream&,
                    Pacient&);
          virtual ~Pacient() {};



};
#endif