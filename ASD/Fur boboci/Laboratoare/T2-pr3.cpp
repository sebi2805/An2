#include <iostream>
#include <fstream>

using namespace std;

struct Nod{
    int info;
    Nod *leg;
};

Nod *L;
int n;

void Init(Nod *&L, int x)
{
    L=new Nod;
    L->info=x;
    L->leg=NULL;
}

void Add(Nod *&L, int x)
{
    Nod *p,*q;
    p=L;
    q=new Nod;
    q->info=x;
    while(p->leg!=NULL)
        p=p->leg;
    p->leg=q;
    q->leg=NULL;
}

void Add_inside(Nod *p, int x)
{
    Nod *q;
    q=new Nod;
    q->info=x;
    q->leg=p->leg;
    p->leg=q;
}

void Citire()
{
    int i,x;
    ifstream fin("date.in");
    fin>>n;
    for(i=0;i<n;i++)
    {
        fin>>x;
        Add(L,x);
    }
}

void Afisare()
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

void Solve()
{
    int med;
    Nod *p;
    p=L;
    while(p->leg!=NULL && p!=NULL)
    {
        med=(p->info+p->leg->info)/2;
        Add_inside(p,med);
        p=p->leg->leg;
    }
}

int main()
{
    L=NULL;
    Init(L,15);
    Citire();
    Afisare();
    Solve();
    Afisare();
    return 0;
}
