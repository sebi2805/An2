#include <iostream>
#include <fstream>

using namespace std;
struct nod{
    int info;
    nod *next;
};

struct lista{
    nod *head;
};

int Cautare(lista L, int info)
{
    for (nod *p = L.head; p != NULL; p = p->next)
        if (p->info == info)
            return 1;
    return 0;
}

void Afisare(lista L)
{
    for (nod* p = L.head; p != NULL; p = p->next)
        cout << p->info << " ";
    cout << "\n";
}

void Inserare(lista &L, int info)
{
    nod *p = new nod;
    p->info = info;
    p->next = NULL;
    if (L.head == NULL)
        L.head = p;
    else
    {
        p->next = L.head;
        L.head = p;
    }
}

void _delete(lista &L, int info)
{
    if (Cautare(L, info))
    {
        if (L.head->info == info)
        {
            nod *p = L.head;
            L.head = L.head->next;
            delete p;
        }
        else
        {
            nod *p;
            for (p = L.head; p->next->info != info; p = p->next);
            ///
            nod *del = p->next;
            p->next = del->next;
            delete del;
        }
    }
}

void clear_list(lista &L)
{
    nod* aux;
    while(L.head != NULL)
    {
        aux = L.head;
        L.head = L.head->next;
        delete aux;
    }
    L.head = NULL;
}

int main()
{
    /** **/
    int x,k;
    ifstream f("elemlista");
    lista L;
    L.head = NULL;
    while (f >> x)
    {
        Inserare(L, x);
    }
    /** **/
    cout<< "Dati elementul care vreti sa fie cautat in lista: "<<"\n";
    cin>>k;
    Cautare(L,k);
    if(Cautare(L,k)==1)
        cout<<"Elementul "<< k <<" a fost gasit in lista"<< "\n";
     cout<<"Sirul afisat :"<< "\n" ;
    Afisare(L);
    _delete(L, k);
    Afisare(L);
    clear_list(L);

    Afisare(L);
    f.close();
    return 0;
}
