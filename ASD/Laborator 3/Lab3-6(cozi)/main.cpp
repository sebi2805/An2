#include <iostream>
#include <queue>
using namespace std;

struct element{
    int i,j;
};

queue <element> Q;

int v[1001][1001],n,frecv[1001][1001],ma[1001][1001],nr = 0;

void reset()
{
    for(int i = 0; i <= n + 1; i++)
    {
        v[i][0] = -1;
        v[0][i] = -1;
        v[n+1][i] = -1;
        v[i][n+1] = -1;
    }
}

void citire()
{
    cin>>n;
    element x;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            cin>>v[i][j];
            if(v[i][j] == 1)
            {
                ma[i][j] = ++nr;
                x.i = i;
                x.j = j;
                frecv[i][j] = 1;
                Q.push(x);
            }
        }
}

void creareMatrice()
{
    element x,y;
    while(!Q.empty())
    {
        x = Q.front();
        Q.pop();
        if(v[x.i - 1][x.j] == 1 && ma[x.i][x.j] < ma[x.i - 1][x.j])
        {
            ma[x.i - 1][x.j] = ma[x.i][x.j];
            if(frecv[x.i - 1][x.j] != 1)
            {
                y.i = x.i - 1;
                y.j = x.j;
                Q.push(y);
            }
        }
        if(v[x.i][x.j - 1] == 1 && ma[x.i][x.j] < ma[x.i][x.j - 1])
        {
            ma[x.i][x.j - 1] = ma[x.i][x.j];
            if(frecv[x.i][x.j - 1] != 1)
            {
                y.i = x.i;
                y.j = x.j - 1;
                Q.push(y);
            }
        }
        if(v[x.i][x.j + 1] == 1 && ma[x.i][x.j] < ma[x.i][x.j + 1])
        {
            ma[x.i][x.j + 1] = ma[x.i][x.j];
            if(frecv[x.i][x.j + 1] != 1)
            {
                y.i = x.i;
                y.j = x.j + 1;
                Q.push(y);
            }
        }
        if(v[x.i + 1][x.j] == 1 && ma[x.i][x.j] < ma[x.i + 1][x.j])
        {
            ma[x.i + 1][x.j] = ma[x.i][x.j];
            if(frecv[x.i + 1][x.j] != 1)
            {
                y.i = x.i + 1;
                y.j = x.j;
                Q.push(y);
            }
        }
    }
}

void afisare()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++) cout<<ma[i][j]<<" ";
        cout<<'\n';
    }
}

int main()
{
    //5
    citire();
    reset();

    creareMatrice();
    afisare();
    return 0;
}
