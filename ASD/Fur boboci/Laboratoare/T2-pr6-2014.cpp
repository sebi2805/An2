#include <iostream>
#include <fstream>

using namespace std;

int n,m;
int a[1000],f[11],b[11];

void Citire()
{
    int i;
    ifstream fin("date.in");
    fin>>n;
    for(i=0;i<n;i++)
    {
        fin>>a[i];
        f[a[i]]++;
    }
    fin.close();
}

void Afisare()
{
    int i;
    for(i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}

void Solve()
{
    int i,j=1;
    for(i=0;i<=10;i++)
        if(f[i]!=0)
            b[j++]=i;
    m=j;
}

void Afisare1()
{
    int i;
    for(i=1;i<m;i++)
        cout<<b[i]<<" ";
    cout<<"\n";
}

int main()
{
    Citire();
    Solve();
    Afisare1();
    return 0;
}
