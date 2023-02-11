#include <iostream>
#include <fstream>

using namespace std;

int n,nr;
int a[1000];

void Citire()
{
    int i;
    ifstream fin("date.in");
    fin>>n>>nr;
    for(i=1;i<=n;i++)
        fin>>a[i];
    fin.close();
}

int Cautare_bin(int x)
{
    int st,dr,m;
    st=1;
    dr=n;
    while(st<=dr)
    {
        m=(st+dr)/2;
        if(a[m]==x)
            return 1;
        if(a[m]>x)
            dr=m-1;
        if(a[m]<x)
            st=m+1;
    }
    return 0;
}

int main()
{
    Citire();
    if(Cautare_bin(nr))
        cout<<"Da";
    else
        cout<<"Nu";
    return 0;
}
