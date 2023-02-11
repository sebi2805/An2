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

int cauta_poz(coada c, int val)
{
    int ind = 1;
    for (nod* p = c.s; p != NULL; p = p->leg)
        if (p->info <= val)
            ind++;
        else
            break;
    return ind;
}

void inserare(coada& c, int val)
{
    if (c.s == NULL)
        inserare_inceput(c, val);
    else
    {
        if (val <= c.s->info)
            inserare_inceput(c, val);
        else
            if (val >= c.f->info)
                inserare_final(c, val);
            else
                inserare_interior(c, val, cauta_poz(c, val));
    }
}

int main()
{
    coada c;
    c.s = NULL;
    c.f = NULL;
    /** **/
    inserare(c, 2);
    inserare(c, 7);
    inserare(c, 1);
    inserare(c, 3);
    inserare(c, 4);
    inserare(c, 5);
    inserare(c, 11);
    inserare(c, 22);
    inserare(c, 9);
    afisare(c);
    return 0;
}
