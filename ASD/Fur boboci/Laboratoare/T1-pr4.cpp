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

int Cautare_sec(int x)
{
    int i;
    for(i=1;i<=n;i++)
        if(a[i]==x)
            return 1;
    return 0;
}

int main()
{
    Citire();
    if(Cautare_sec(nr))
        cout<<"Da";
    else
        cout<<"Nu";
    return 0;
}
