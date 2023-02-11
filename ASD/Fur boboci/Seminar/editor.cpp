#include <iostream>
#include <fstream>
#include <cstring>
#include <stack>

using namespace std;
ifstream fin("editor.in");
ofstream fout("editor.out");

stack <int> S;
stack <int> R;
char m[31][60001];
int T;

void Read()
{
    int i;
    char c;
    fin>>T;
    for(i=0;i<=T;i++)
        fin.getline(m[i],60000);
}

void Solve()
{
    int i,j;
    for(i=1;i<=2;i++)
    {
        while(R.empty()==0)
            R.pop();
        j=0;
        while(m[i][j]!='E')
        {
            if(m[i][j]!='*')
                S.push(1);
            else if(S.empty()==0)
                S.pop();
            j++;
        }
        while(S.empty()==0)
        {
            if(S.top()==']')
            {
                R.push(2);
                S.pop();
            }
            if(S.top()==')')
            {
                R.push(1);
                S.pop();
            }
            if(S.top()=='(' && R.top()==1)
            {
                S.pop();
                R.pop();
            }
            if(S.top()=='[' && R.top()==2)
            {
                S.pop();
                R.pop();
            }
        }
        if(S.empty()==1 && R.empty()==1)
            fout<<":)";
        else
            fout<<":(";
    }
}

void Afisare()
{
    while(S.empty()==0)
    {
        cout<<S.top()<<" ";
        S.pop();
    }
}

int main()
{
    Read();
    Solve();
    //Afisare();
    return 0;
}
