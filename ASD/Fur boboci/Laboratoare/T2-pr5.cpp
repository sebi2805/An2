#include <iostream>
#include <fstream>

using namespace std;

struct Nod{
    int info;
    Nod *leg;
};

Nod *L,*J,*K;
int n,m;

void Init(Nod *&H, int x)
{
    H=new Nod;
    H->info=x;
    H->leg=NULL;
}

void Add(Nod *&H, int x)
{
    Nod *p,*q;
    p=H;
    q=new Nod;
    q->info=x;
    while(p->leg!=NULL)
        p=p->leg;
    p->leg=q;
    q->leg=NULL;
}

void Citire()
{
    int cif;
    ifstream fin("date.in");
    fin>>n;
    while(n!=0)
    {
        cif=n%10;
        Add(L,cif);
        n=n/10;
    }

    fin>>m;
    while(m!=0)
    {
        cif=m%10;
        Add(J,cif);
        m=m/10;
    }
}

void Afisare(Nod *H)
{
    Nod *p;
    p=H->leg;
    while(p!=NULL)
    {
        cout<<p->info<<" ";
        p=p->leg;
    }
    cout<<"\n";
}

void Make_sum(Nod *H, Nod *G)
{
    int x,y,z,ok1,ok2;
    Nod *p,*q;
    p=H->leg;
    q=G->leg;
    ok1=ok2=1;
    while(ok1==1 && ok2==1)
    {
        if(p!=NULL) ok1=1;
        else ok1=0;
        if(q!=NULL) ok2=1;
        else ok2=0;
        if(ok1==1 && ok2==1)
        {
            x=p->info + q->info;
            y=x%10;
            Add(K,y);
            z=x/10;
            p->leg->info+=z;
            p=p->leg;
            q=q->leg;
        }
    }

    while(p!=NULL)
    {
        x=p->info;
        Add(K,x);
        p=p->leg;
    }

    while(q!=NULL)
    {
        x=q->info;
        Add(K,x);
        q=q->leg;
    }
}

int main()
{
    L=NULL;
    J=NULL;
    K=NULL;
    Init(L,-1);
    Init(J,-1);
    Init(K,-1);
    Citire();
    Afisare(L);
    Afisare(J);
    Make_sum(L,J);
    Afisare(K);
    return 0;
}
