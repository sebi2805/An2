#include <fstream>
using namespace std;
ifstream fin("lacoada.in");
ofstream fout("lacoada.out");
int n,k,a[1000005],pr, ul;

void Imbrancire(int pers)
{
   int i,j,x;
   j=-1;
    for(i=pr;i<=ul && j==-1;i++)
        if(a[i]==pers) j=i;
    if(j!=pr)
        {
            a[pr]=pers;
            for(i=j;i>pr;i--)
                a[i]=a[i-1];
        }

}
void Init()
{
    int i;
    for(i=1;i<=n;i++)
        a[i]=i;
    pr=1;
    ul=n;
}
void Solve()
{
    int i,x;
    for(i=1;i<=k;i++)
    {
        fin>>x;
        if(x==1) pr++;
        else if(x==2)
        {
            ul++;
            a[ul]=ul;
        }
        else if(x==3)
        {
            fin>>x;
            Imbrancire(x);
        }
    }
}
void Afisare()
{
    int i;
    fout<<ul-pr+1<<"\n";
    for(i=pr;i<=ul;i++)
        fout<<a[i]<<" ";
    fout<<"\n";
}
int main()
{
    fin>>n>>k;
    Init();
    Solve();
    Afisare();
    return 0;
}
