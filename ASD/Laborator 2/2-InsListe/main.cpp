#include <iostream>

using namespace std;

struct nod {

    int info;
    nod* leg;
};

struct coada {
    nod* s;
    nod* f;
};

void inserare_inceput(coada& c, int k)
{
    nod* p = new nod;
    p->info = k;
    p->leg = NULL;
    if (c.s == NULL)
        c.s = c.f = p;
    else
    {
        p->leg = c.s;
        c.s = p;
    }
}

void inserare_interior(coada& c, int k, int poz)
{
    if (poz < 1)
        return;
    if (poz == 1)
        inserare_inceput(c, k);
    else
    {
        nod* aux = c.s;
        for (int i = 2; i < poz && aux != NULL; i++)
            aux = aux->leg;
        if (aux != NULL)
        {
            nod* p = new nod;
            p->info = k;
            ///
            p->leg = aux->leg;
            aux->leg = p;
            if (aux == c.f)
                c.f = p;
        }
    }
}

void inserare_final(coada& c, int k)
{
    nod* p = new nod;
    p->info = k;
    p->leg = NULL;
    if (c.f == NULL)
        c.s = c.f = p;
    else
    {
        c.f->leg = p;
        c.f = p;
    }
}

void afisare(coada c)
{
    for (nod* p = c.s; p != NULL; p = p->leg)
        cout << p->info << " ";
    cout << "\n";
}

int main()
{
    coada c;
    c.s = NULL;
    c.f = NULL;
    /** **/
    inserare_inceput(c, 3);
    inserare_inceput(c, 4);
    inserare_final(c, 11);
    inserare_inceput(c, 7);
    inserare_final(c, 10);
    cout << "\n";
    inserare_interior(c, 22, 5);
    inserare_final(c, 111);
    inserare_interior(c, 3434, 8);
    inserare_final(c, 2121);
    afisare(c);
    return 0;
}
