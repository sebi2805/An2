#ifndef CLASICE
#define CLASICE
#include <iostream>
#include "BToy.h"
class Clasice : public BToy
{
    std::string material, culoare;

public:
    Clasice(std::string denumire = "undefined", std::string tip = "undefined", int dimensiune = 0, std::string material = "undefined", std::string culoare = "undefined")
        : BToy(ToyCategory::Clasice, denumire, tip, dimensiune), material(material), culoare(culoare){};
    Clasice(Clasice &);
    void print(std::ostream &) const override;
    void read(std::istream &) override;
    friend std::ostream &operator<<(std::ostream &, Clasice &);
    friend std::istream &operator>>(std::istream &, Clasice &);
};
#endif