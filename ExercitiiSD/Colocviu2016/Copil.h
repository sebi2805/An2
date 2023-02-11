#ifndef COPIL
#define COPIL
#include <iostream>
#include "Pacient.h"

class CopilClass: virtual public Pacient {

          std::string numeM, prenumeM, numeT, prenumeT, antecedente;
          int an, zi, luna;
          double proteina;


public:
          void print(std::ostream&) const override;
          void read(std::istream&) override;
          bool risc() const override;
          CopilClass(CopilClass&);
          CopilClass(std::string nume = "undefined", std::string prenume = "undefined",
                    std::string adresa = "undefined", int valoareColesterol = 0, int tensiune = 0, int varsta = 0,
                    std::string numeM = "undefined", std::string prenumeM = "undefined", std::string antecedente = "undefined",
                    std::string numeT = "undefined", std::string  prenumeT = "undefined", int an = 0, int zi = 0, int luna = 0,
                    int ziC = 0, int lunaC = 0, int anC = 0, int ziT = 0, int lunaT = 0, int anT = 0,
                    double proteina = 0)
                    : Pacient(PacientType::Copil, nume, prenume, adresa, valoareColesterol, tensiune, varsta, ziC, lunaC, anC, ziT, lunaT, anT),
                    numeT(numeT), prenumeT(prenumeT), numeM(numeM), prenumeM(prenumeM), an(an), zi(zi), luna(luna), proteina(proteina) {

          };
          friend std::ostream& operator <<(std::ostream&, const CopilClass&);
          friend std::istream& operator >>(std::istream&,
                    CopilClass&);



};
#endif