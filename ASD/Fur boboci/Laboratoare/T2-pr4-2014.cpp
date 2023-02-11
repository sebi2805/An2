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

void Inserare(int poz, int x)
{
    int i;
    i=n;
    while(i>=poz)
    {
        a[i+1]=a[i];
        i--;
    }
    a[poz]=x;
    n++;
}

int main()
{
    Citire();
    Afisare();
    Inserare(5,666);
    Afisare();
    return 0;
}
