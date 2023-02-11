#include <iostream>
#include <vector>
using namespace std;
int peak(vector<int>& a) {
    int st = 0, dr = a.size() - 1, mij;
    while (dr - st > 1) {
        cout << st << " " << dr << " " << mij << endl;
        mij = (dr + st + 1) / 2;
        if (a[st] < a[dr]) { st = mij; }
        else { dr = mij; }
    }
    return a[st] > a[dr] ? st : dr;
}