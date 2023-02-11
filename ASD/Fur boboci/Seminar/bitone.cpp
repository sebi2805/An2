#include <fstream>
using namespace std;
ifstream fin ("bitone.in");
ofstream fout ("bitone.out");
int n, q;
int a[1000010];

int Verifica(int x, int y)
{
    if(x==y) return 1;
    for(;a[x]<=a[x+1]&&x<y;x++);
    if (y<=x)
        return 1;
    for(;a[x]>=a[x+1]&&x<y;x++);
    if(y<=x)
        return 1;
    return 0;
}

int main()
{

    int i,x,y;
    fin>>n>>q;
    for(i=1;i<=n;i++)
        fin>>a[i];

    for(i=1;i<=q;i++)
    {
        fin>>x>>y;
        fout<<Verifica(x,y);
    }
    return 0;
}
