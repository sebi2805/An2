#include <iostream>
#include <fstream>

using namespace std;

struct Nod{
    int info;
    Nod *leg;
};

Nod *L;
int n;

void Add(Nod *&L, int x)
{
    Nod *p;
    p=new Nod;
    p->info=x;
    p->leg=NULL;
    if(L==NULL)
        L=p;
    else
    {
        p->leg=L;
        L=p;
    }
}

void Citire()
{
    int i,x;
    ifstream fin("date.in");
    fin>>n;
    for(i=1;i<=n;i++)
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

void Numara()
{
    int cntP=0,cntN=0,sN=0;
    Nod *p;
    p=L;
    while(p!=NULL)
    {
        if(p->info>=0)
            cntP++;
        else
        {
            sN += p->info;
            cntN++;
        }
        p=p->leg;
    }
    cout<<cntP<<" "<<sN/cntN<<"\n";
}

int main()
{
    L=NULL;
    Citire();
    Afisare();
    Numara();
    return 0;
}
