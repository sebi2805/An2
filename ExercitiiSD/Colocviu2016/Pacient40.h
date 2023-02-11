#ifndef PACIENT40
#define PACIENT40
#include <iostream>
#include "Pacient.h"
enum Sedentarism {
          scazut, mediu, ridicat
};
class Pacient40:virtual public Pacient {

          bool fum;
          Sedentarism sed;
public:
          void print(std::ostream&) const override;
          void read(std::istream&) override;
          void setSed(Sedentarism);
          Pacient40(Pacient40&);
          bool risc() const override;
          void setFum(bool);
          Pacient40(std::string nume = "undefined", std::string prenume = "undefined",
                    std::string adresa = "undefined", int valoareColesterol = 0, int tensiune = 0, int varsta = 0,
                    bool fum = false, Sedentarism sed = Sedentarism::scazut, int ziC = 0, int lunaC = 0, int anC = 0, int ziT = 0, int lunaT = 0, int anT = 0)
                    : Pacient(PacientType::Adult, nume, prenume, adresa, valoareColesterol, tensiune, varsta, ziC, lunaC, anC, ziT, lunaT, anT), fum(fum), sed(sed) {

          };
          friend std::ostream& operator <<(std::ostream&, const Pacient40&);
          friend std::istream& operator >>(std::istream&,
                    Pacient40&);


};
#endif