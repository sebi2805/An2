#include <iostream>

using namespace std;

struct Nod{
    int info;
    Nod *leg;
};

void Add(Nod *&p, int x)
{
    Nod *q;
    q=new Nod;
    q->info=x;
    q->leg=p->leg;
    p->leg=q;
}

void Add_end(Nod *&L, int x)
{
    Nod *p;
    p=L;
    while(p->leg!=NULL)
        p=p->leg;
    Add(p,x);
}

void Add_begin(Nod *&L, int x)
{
    Nod *p;
    p=new Nod;
    p->info=x;
    p->leg=L;
    L=p;
}

void Add_inside(Nod *&L, int x, int poz)
{
    int cnt=0;
    Nod *p;
    p=L;
    while(p!=NULL && cnt<poz)
    {
        p=p->leg;
        cnt++;
    }
    Add(p,x);
}

Nod * Cauta_elem_valoare(Nod *L, int x)
{
    int ok=0;
    Nod *p, *q;
    p=L;
    while(p!=NULL && ok==0)
    {
        if(p->leg->info==x)
        {
            ok=1;
            q=p;
        }
        p=p->leg;
    }
    if(ok==1)
        cout<<"Elementul a fost gasit\n";
    else
            cout<<"Elementul nu a fost gasit\n";
    return q;
}

Nod * Cauta_elem_poz(Nod *L, int poz)
{
    int ok=0,i;
    Nod *p,*q;
    p=L;
    while(p!=NULL && ok==0)
    {
        i++;
        if(i==poz)
        {
            ok=1;
            q=p;
        }
        p=p->leg;
    }
    if(ok==1)
        cout<<"Elementul a fost gasit si acesta este: "<<p->info<<"\n";
    else
        cout<<"Elementul nu a fost gasit\n";
    return q;
}

void Sterge_valoare(Nod *&L, int x)
{
    Nod *p,*q;
    q=new Nod;
    p=Cauta_elem_valoare(L,x);
    q=p->leg;
    p->leg=p->leg->leg;
    delete q;
}

void Sterge_pozitie(Nod *&L, int poz)
{
    Nod *p,*q;
    q=new Nod;
    p=Cauta_elem_poz(L,poz);
    q=p->leg;
    p->leg=p->leg->leg;
    delete q;
}

void Sterge_lista(Nod *L)
{
    delete L;
}

void Afisare(Nod *L)
{
    Nod *p;
    p=L;
    while(p!=NULL)
    {
        cout<<p->info<<" ";
        p=p->leg;
    }
    cout<<"\n";
}

int main()
{
    int i,n,x;
    ///declararea listei si legarea primului nod la NULL
    Nod *L;
    L=NULL;

    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        Add_begin(L,x);
    }
    cout<<"Lista imediat dupa citire: ";
    Afisare(L);
    cout<<"\n";

    ///Parametrii functiei Add_inside sunt asa: L-lista, apoi valoarea pe care vrei sa o adaugi si apoi la ce pozitie
    ///Trebuie sa ai grija sa pui o pozitie mai mica decat n-ul citit ca altfel iti crapa **eu am facut, a se evita :))**
    cout<<"Lista dupa ce am adaugat in interior: ";
    Add_inside(L,7789,3);
    Afisare(L);
    cout<<"\n";

    cout<<"Lista dupa ce am adaugat la sfarsit";
    Add_end(L,88888);
    Afisare(L);
    cout<<"\n";

    ///afisarile functiilor astea 2 sunt mai sus in definirea lor
    cout<<"Cautari diverse\n\n";
    Cauta_elem_valoare(L,3);
    Cauta_elem_poz(L,2);

    ///Cauta si sterge elementul cu valoarea pe care o pui ca parametru
    ///**din nou, iti crapa daca pui ceva care nu e in lista**
    cout<<"\nStergeri diverse\n\n";
    Sterge_valoare(L,1);
    Afisare(L);
    cout<<"\n";

    ///Cauta si sterge elementul de pe pozitia pe care o pui acolo
    ///**e evident cazul in care iti crapa**
    Sterge_pozitie(L,2);
    Afisare(L);
    cout<<"\n";

    ///so obviously
    Sterge_lista(L);
    ///nu am nici o idee de ce am mai pus afisarea O.O dupa stergerea listei.
    ///Afisare(L);
    return 0;
}
