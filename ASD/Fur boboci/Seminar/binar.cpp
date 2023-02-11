#include <fstream>

#define In "binar.in"
#define Out "binar.out"
#define Nmax  2015

using namespace std;
ofstream g(Out);

char a[Nmax][Nmax];
int sol[Nmax],n,m;
int v0[Nmax],v1[Nmax];

inline void Read()
{
    ifstream f(In);
    f>>n>>m;
    int i;
    for(i = 1;i <= n; ++i)
        f>>(a[i]+1);
    for(i = 1;i <= m; ++i)
        sol[i] = i;
    f.close();
}

inline void RadixSort(const int lin,const int Left,const int Right)
{
    if(Left>=Right || lin==n+1)
        return ;
    int i,j ,ind;
    v0[0] = v1[0] = 0;
    for(i = Left;i <= Right; ++i)
    {
        if(a[lin][sol[i]]-'0')
            v1[++v1[0]] = sol[i];
        else
            v0[++v0[0]] = sol[i];
    }
    j = Left;
    for(i = 1;i <= v0[0]; ++i)
        sol[j++] = v0[i];
    ind = j;
    for(i = 1;i <= v1[0]; ++i)
        sol[j++] = v1[i];
    RadixSort(lin+1,Left,ind-1);
    RadixSort(lin+1,ind,Right);
}

inline void Write()
{
    int i;
    for(i=1;i<=m;++i)
        g<<sol[i]<<" ";
    g<<"\n";
    g.close();
}

int main()
{
    Read();
    RadixSort(1,1,m);
    Write();
    return 0;
}
