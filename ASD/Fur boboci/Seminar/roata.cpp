#include <fstream>

using namespace std;
ifstream fin("roata.in");
ofstream fout("roata.out");

int p,n;
int t[100010],v[500],w[370];

void Citire()
{
    int i;
    long long s;
    fin>>n>>p;
    s=0;
    for(i=1;i<=p;i++)
    {
        fin>>t[i];
        s+=t[i];
    }
    fout<<s<<"\n";
}

void Solve()
{
    int i,j,pas,poz,minim;
    if(n>=p)
    {
        for(i=1;i<=p;i++)
        {
            poz=1;
            minim=100004;
            for(j=1;j<=p;j++)
                if(minim>t[j])
                {
                    poz=j;
                    minim=t[j];
                }
            fout<<poz<<" ";
            t[poz]=100004;
        }
        fout<<poz<<" ";
    }
    else
    {
        for(i=1;i<=n;i++)
        {
            v[i]=t[i];
            w[i]=i;
        }

        for(i=n+1;i<=p;i++)
        {
            poz=1;
            for(j=1;j<=n;j++)
                if(v[poz]>v[j])
                    poz=j;
            minim=v[poz];

            for(j=1;j<=n;j++)
                v[j]=v[j]-minim;

            fout<<w[poz]<<" ";

            v[poz]=t[i];
            w[poz]=i;
        }
        for(i=1;i<=n;i++)
        {
            poz=1;
            for(j=1;j<=n;j++)
                if(v[poz]>v[j])
                    poz=j;
            fout<<w[poz]<<" ";
            v[poz]=100004;
        }
        fout<<poz<<"\n";
    }
}

int main()
{
    Citire();
    Solve();
    return 0;
}


#include <iostream>
#include <fstream>
#define inf 999999999
using namespace std;
long c[400],poz[400],sol[100009];
ifstream fin("roata.in");
ofstream fout("roata.out");

int main()
{long i,nr,n,m,p;
long ture,minim=inf;
    fin>>n>>m;
long long suma=0;
nr=0;
p=0;
ture=0;
    for(i=1;i<=m;i++)
    {
        do
        {p++;
        if(p==n+1){p=1;ture=minim;minim=inf;}
        c[p]-=ture;
        if(c[p] && c[p]<minim)minim=c[p];
        }while(c[p]);

        if(poz[p])sol[++nr]=poz[p];
        fin>>c[p];if(c[p]<minim)minim=c[p];
        suma+=c[p];
        poz[p]=i;
    }

    while(p<n)
    {p++;
     c[p]-=ture;
     if(!c[p])if(poz[p])sol[++nr]=poz[p];
    }

    fout<<suma<<'\n';
    for(i=1;i<=nr;i++)fout<<sol[i]<<' ';

minim=inf;
for(p=1;p<=n;p++)
    if(c[p] && c[p]<minim)minim=c[p];

long newmin,ultimul;
    while(minim!=inf)
    {newmin=inf;
    for(p=1;p<=n;p++)
        if(c[p])
        {if(c[p]==minim){ultimul=p;c[p]=0;fout<<poz[p]<<' ';}
                 else
                    if(c[p]<newmin)newmin=c[p];}
     minim=newmin;}

     fout<<'\n'<<ultimul;


}
