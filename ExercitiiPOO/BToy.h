#ifndef btoy
#define btoy
#include <iostream>
enum class ToyCategory
{
    Unknown,
    Clasice,
    Electronice,
    Educative,
    Moderne
};
class BToy
{
    std::string denumire, tip;
    int dimensiune;
    static int numarJucarii;
    static int numarClasice;
    static int numarModerne;
    static int numarElectronice;
    static int numarEducative;

public:
    BToy(ToyCategory category = ToyCategory::Unknown, std::string denumire = "undefined", std::string tip = "undefined", int dimensiune = 0)
        : denumire(denumire), tip(tip), dimensiune(dimensiune)
    {
        numarJucarii++;
        switch (category)
        {
        case ToyCategory::Clasice:
        {
            numarClasice++;
            break;
        }
        case ToyCategory::Educative:
        {
            numarEducative++;
            break;
        }
        case ToyCategory::Electronice:
        {
            numarElectronice++;
            break;
        }
        case ToyCategory::Moderne:
        {
            numarModerne++;
            break;
        }

        default:
            break;
        }
    };
    BToy(BToy &);
    virtual void print(std::ostream &) const;
    virtual void read(std::istream &);
    friend std::ostream &operator<<(std::ostream &, BToy &);
    friend std::istream &operator>>(std::istream &, BToy &);
    static void printStatics()
    {
        std::cout << "Numar jucarii" << numarJucarii << " clasice: " << numarClasice << " electronice "
                  << numarElectronice << " educative " << numarEducative << " moderne " << numarModerne << std::endl;
    }
    const std::string getDenumire() const;
    const std::string getTip() const;
    static void setNumarModerne()
    {
        numarModerne++;
    }
};
#endif