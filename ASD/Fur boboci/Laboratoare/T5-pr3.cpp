#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("date.in");

struct Nod
{
    int info;
    Nod *next,*prev;
};
Nod *Fst[100], *Lst[100];

int n,m;

void Init()
{
    int i;
    for(i=1;i<=m;i++)
        Fst[i]=Lst[i]=NULL;
}

void Add_end(int prt, int val)
{
    Nod *p;
    p=new Nod;
    p->info=val;
    p->next=NULL;
    p->prev=NULL;

    if(Fst[prt]==NULL)
    {
        Fst[prt]=p;
        Lst[prt]=Fst[prt];
    }
    else
    {
        Lst[prt]->next=p;
        p->prev=Lst[prt];
        Lst[prt]=p;
    }
}

void Add_begin(int prt, int val)
{
    Nod *p;
    p=new Nod;
    p->info=val;
    p->prev=NULL;
    p->next=Fst[prt];
    if(Fst[prt]!=NULL)
        Fst[prt]->prev=p;
    Fst[prt]=p;
}

void Extract_first(int prt)
{
    if(Fst[prt])
    {
        Nod *q;
        q=Fst[prt];
        cout<<Fst[prt]->info<<" ";
        Fst[prt]=Fst[prt]->next;
        Fst[prt]->prev=NULL;
        delete q;
    }
}

void Extract_last(int prt)
{
    if(Lst[prt])
    {
        Nod *q;
        q=Lst[prt];
        cout<<Lst[prt]->info<<" ";
        Lst[prt]=Lst[prt]->prev;
        Lst[prt]->next=NULL;
        delete q;
    }
}

void Citire()
{
    int i,x,y;
    fin>>n>>m;
    for(i=1;i<=n;i++)
    {
        fin>>x>>y;
        Add_end(x,y);
        //Add_begin(x,y);
    }
}

void Afisare_first()
{
    int i;
    for(i=1;i<=m;i++)
    {
        while(Fst[i]->next!=NULL)
            Extract_first(i);
        cout<<Fst[i]->info;
        Fst[i]=NULL;
        cout<<"\n";
    }
}

void Afisare_last()
{
    int i;
    for(i=1;i<=m;i++)
    {
        while(Lst[i]->next!=NULL)
            Extract_last(i);
        cout<<Lst[i]->info;
        Lst[i]=NULL;
        Fst[i]=NULL;
        cout<<"\n";
    }
}

int main()
{
    Init();
    Citire();
    Afisare_first();
    return 0;
}
