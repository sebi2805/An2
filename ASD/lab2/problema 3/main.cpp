#include <iostream>
#include <fstream>
using namespace std;
struct nod{
 int info; nod *adr;};
void afisare (nod *p)
{
    cout<<"Lista este: \n";
    if (p!=NULL)
    {
        do {
            cout<<p->info<<" ";
            p=p->adr;
        }while (p!=NULL);
    }
    cout<<"\n";
}
int main()
{
    nod *st,*p, *oldp, *q;
    int x;
    ifstream f("text.in");
    if (f>>x)
    {
        st=new nod;
        st->info=x;
        st->adr=NULL;
        while (f>>x){
            p=st;
            oldp=NULL;
            do{
                if (p->info<=x)
                {
                    oldp=p;
                    p=p->adr;
                }else
                break;
            }while (p!=NULL);
            q=new nod;
            q->info=x;
            q->adr=p;
            if (oldp!=NULL)
                oldp->adr=q;
            else
                st=q;
        }
    }
    f.close();
    afisare(st);
    return 0;
}
