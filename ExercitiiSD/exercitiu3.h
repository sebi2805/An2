#include <iostream>
#include <vector>
using namespace std;
int existsAlternate(vector<int>& a, int e) {
    int st = 0, dr = a.size() - 1, mij;
    while (dr - st >= 1) {
        mij = (dr + st + 1) / 2;

        if (dr - st == 1) { return a[st] == e ? st : a[dr] == e ? dr : -1; }
        if (mij % 2 == 0) {
            if (a[mij] + 1 > e) { dr = mij; }
            else { st = mij; }
        }
        else {
            if (a[mij] - 1 > e) { dr = mij; }
            else { st = mij; }
        }
    }
    return -1;


};