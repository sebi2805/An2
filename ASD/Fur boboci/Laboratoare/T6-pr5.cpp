#include <iostream>

using namespace std;

struct Nod
{
    Nod *lft, rgt;
    int val, LeftSize;
}
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

void Init()

void SRD(Nod *rad)
{
    int cnt=0;
    if(rad->lft!=NULL || rad->rgt!=NULL)
    {
        SRD(rad->lft);
        rad->LeftSize=rad->lft->LeftSize+1;
        SRD(rad->rgt);
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
    return 0;
}
