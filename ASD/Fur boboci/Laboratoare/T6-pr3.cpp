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

void SRD(Nod *rad)
{
    if(rad!=NULL)
    {
        SRD(rad->lft);
        cout<<rad->info<<" ";
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
    SRD(rad);
    cout<<"\n";
    return 0;
}
