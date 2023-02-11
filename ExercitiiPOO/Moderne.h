#ifndef MODERNE
#define MODERNE
#include <iostream>
#include "Educative.h"
#include "Electronice.h"
class Moderne : virtual public Electronice, virtual public Educative
{
    std::string brand;

public:
    Moderne(std::string denumire = "undefined", std::string tip = "undefined",
            int dimensiune = 0, int numarBaterii = 1, std::string abilitatea = "undefined", std::string brand = "undefined")
        : Electronice(denumire, tip, dimensiune, numarBaterii), Educative(denumire, tip, dimensiune, abilitatea), brand(brand) { BToy::setNumarModerne(); };
    Moderne(Moderne &);
    void print(std::ostream &) const override;
    void read(std::istream &) override;
    friend std::ostream &operator<<(std::ostream &, Moderne &);
    friend std::istream &operator>>(std::istream &, Moderne &);
};
#endif