#include <iostream>

using namespace std;

struct Nod
{
    int info;
    Nod *lft, *rgt;
};
Nod *rad;

void Creare(Nod *&rad, int x)
{
    if(rad==NULL)
    {
        rad=new Nod;
        rad->info=x;
        rad->lft=NULL;
        rad->rgt=NULL;
    }
    else if (x<rad->info)
        Creare(rad->lft,x);
        else if(x>rad->info)
            Creare(rad->rgt,x);
}

void Inserare(int x)
{
    Nod *p,*q;
    p=rad;
    while(p!=NULL)
    {
        q=p;
        if(x<=p->info)
            p=p->lft;
        else
            p=p->rgt;
    }
    p=new Nod;
    p->info=x;
    p->lft=p->rgt=NULL;
    if(x>q->info)
        q->rgt=p;
    else
        q->lft=p;
}

void SRD(Nod *rad)
{
    if(rad!=NULL)
    {
        SRD(rad->lft);
        cout<<rad->info<<" ";
        SRD(rad->rgt);
    }
}

void RSD(Nod *rad)
{
    if(rad!=NULL)
    {
        cout<<rad->info<<" ";
        RSD(rad->lft);
        RSD(rad->rgt);
    }
}

void SDR(Nod *rad)
{
    if(rad!=NULL)
    {
        SDR(rad->lft);
        SDR(rad->rgt);
        cout<<rad->info<<" ";
    }
}

int main()
{
    rad=NULL;
    int i,n,x;
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>x;
        Creare(rad,x);
    }
    SRD(rad);
    cout<<"\n";
    RSD(rad);
    cout<<"\n";
    SDR(rad);
    cout<<"\n";
    return 0;
}
