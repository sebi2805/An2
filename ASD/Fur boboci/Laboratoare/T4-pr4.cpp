#include <iostream>
#include <stack>

using namespace std;

void Citire()
{
    stack <int> S;
    int n,i,ok;
    char x;
    cin>>n;
    ok=1;
    for(i=0;i<n;i++)
    {
        cin>>x;
        if(S.empty()==0)
        {
            if(S.top()==x)
                S.pop();
            else if(S.size()<2)
                S.push(x);
                else ok=0;
       }
       else S.push(x);
    }
    if(ok==1)
        cout<<"Se poate";
    else
        cout<<"Nu se poate";
}

int main()
{
    Citire();
    return 0;
}
