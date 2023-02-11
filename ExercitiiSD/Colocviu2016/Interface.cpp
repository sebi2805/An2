#include "Interface.h"
void Interface::start() {
          int i = 1;
          while (i) {
                    std::cout << "Ce doriti sa faceti?\n1.Adaugati pacienti\n2.Afisati toti pacientii\n3.Afisati adultii cu risc\n4.Copii risc\n5.Cautati dupa nume" << std::endl;
                    std::cin >> i;
                    switch (i)
                    {
                    case 1:
                    { mainDoctor.addPacient();
                    break;}
                    case 2:
                    {mainDoctor.print(std::cout);
                    break;}
                    case 3:
                    {mainDoctor.searchAdult();
                    break;}
                    case 4:
                    {mainDoctor.searchChild();
                    break;}
                    case 5:
                    {std::cout << "Ce nume cautati" << std::endl;
                    std::string name;
                    std::cin >> name;
                    mainDoctor.searchByName(name);
                    break;}

                    default:
                              break;
                    }
          }
};