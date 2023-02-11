#include <iostream>
#include <fstream>

using namespace std;

struct Nod{
    int info;
    Nod *leg;
};

Nod *L,*J,*AUX,*K;
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
    int x,y,ok1,ok2;
    x = y = 0;
    Nod *p,*q;
    p=H;
    q=G;
    while(p->info == -1 || q->info == -1)
    {
        p = p->leg;
        q = q->leg;
    }
    ok1=ok2=1;
    while(ok1==1 || ok2==1 || x != 0)
    {
        if(p!=NULL) x += p->info;
        else ok1=0;
        if(q!=NULL) x += q->info;
        else ok2=0;
        y=x%10;
        Add(K,y);
        x=x/10;
        if (ok1 == 1) p=p->leg;
        if (ok2 == 1) q=q->leg;
    }
}

void Add_Head(Nod *H)
{
    Nod *p;
    p=new Nod;
    p->info=-1;
    p->leg=H;
    H=p;
}

void Make_prod(Nod *H, Nod *G)
{
    int x,y,z,ok1,ok2,v1,v2;
    Nod *p,*q;
    p=H->leg;
    ok1=ok2=1;
    while(ok1==1)
    {
        if(p!=NULL) ok1=1;
        else ok1=0;
        if(ok1==1)
        {
            v1=p->info;
            ok2=1;
            x=0;
            q=G->leg;
            while(ok2==1)
            {
                if(q!=NULL) ok2=1;
                else ok2=0;
                if(ok2==1)
                {
                    v2=q->info;
                    x=v1*v2+x;
                    y=x%10;
                    Add(AUX,y);
                    x=x/10;
                    q=q->leg;
                }
            }
            p=p->leg;
            //Make_sum(AUX,K);
        }
    }
}

int main()
{
    L=NULL;
    J=NULL;
    K=NULL;
    AUX=NULL;
    Init(L,-1);
    Init(J,-1);
    Init(K,-1);
    Init(AUX,-1);
    Citire();
    Afisare(L);
    Afisare(J);
    Make_prod(L,J);
    Afisare(K);
    return 0;
}
