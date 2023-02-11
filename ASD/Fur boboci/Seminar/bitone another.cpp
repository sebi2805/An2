#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("bitone.in");
ofstream g ("bitone.out");

const int NMAX = 1000000 + 1;

int n, m;
int v[NMAX];


void citeste() {
    f >> n;
    for (int i = 1; i <= n; i++) f >> v[i];
}

int Check(int i, int j)
{

    while(v[i]<=v[i+1] && i<j) i++;
    if (i>=j) return 1;
    while(v[i]>=v[i+1] && i<j) i++;
    if(i>=j) return 1;

    return 0;
}
void rezolva() {
    f >> m;
    int a, b;
    int i,j;
    for(i=1;i<=m;i++)
    {
        f>>a>>b;
        if (a == b)
            g << 1;
        else
        g<<Check(a,b);
    }
}


int main() {
    citeste();
    rezolva();
    return 0;
}
