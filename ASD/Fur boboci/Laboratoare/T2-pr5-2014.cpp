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

void Afisare()
{
    int i;
    for(i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}

int Cauta(int x)
{
    int i;
    for(i=1;i<=n;i++)
        if(a[i]==x)
            return i;
    return -1;
}

void Stergere(int x)
{
    int i,k;
    k=Cauta(x);
    if(k!=-1)
    {
        for(i=k;i<=n;i++)
            a[i]=a[i+1];
        Afisare();
    }
    else
        cout<<"Elementul cerut nu se gaseste in structura!!!\n";
}

int main()
{
    Citire();
    Afisare();
    Stergere(41);
    return 0;
}
