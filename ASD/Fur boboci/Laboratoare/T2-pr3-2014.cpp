#include <iostream>
#include <fstream>

using namespace std;

int n;
int a[1000];

void Citire()
{
    int i;
    ifstream fin("date.in");
    fin>>n;
    for(i=1;i<=n;i++)
        fin>>a[i];
    fin.close();
}

void Maxim()
{
    int i,maxim=0;
    for(i=1;i<=n;i++)
        if(a[i]>maxim)
            maxim=a[i];
    cout<<maxim<<"\n";
}

void Poz_Min()
{
    int i,minim=1000000,poz;
    for(i=1;i<=n;i++)
        if(a[i]<minim)
        {
            minim=a[i];
            poz=i;
        }
    cout<<poz<<"\n";
}

int main()
{
    Citire();
    Maxim();
    Poz_Min();
    return 0;
}
