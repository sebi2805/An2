//clang-format off
#include <iostream>
#include <vector>
#include "exercitiu1.h"
#include "exercitiu2.h"
#include "exercitiu3.h"
#include "exercitiu4.h"
using namespace std;
#include <cstdlib>
#include <ctime>
class minHeap
{
    vector<int> arr;
public:
    minHeap() {};
    int father(int i) {
        return (i - 1) / 2;
    }
    void swap(int i, int j) {
        int aux = arr[i];
        arr[i] = arr[j];
        arr[j] = aux;
    }
    void add(int i) {

        arr.push_back(i);

        int j = arr.size() - 1;
        while (j >= 0 && arr[father(j)] > arr[j])
        {

            swap(j, father(j));
            j = father(j);
        }
    }
    void print() {
        for (auto i : arr)
            std::cout << i << " ";
    }
    int peek() {
        int peek = arr[0];
        if (arr.size() == 1) return peek;
        swap(0, arr.size() - 1);
        arr.pop_back();
        int j = 0;
        while (j < arr.size() - 1 && (arr[j] > arr[(j + 1) * 2] || arr[j] > arr[(j + 1) * 2 - 1] && (j + 1) * 2 <= arr.size() - 1)) {

            if (arr[(j + 1) * 2] > arr[(j + 1) * 2 - 1]) {
                if (arr[(j + 1) * 2 - 1] < arr[j])
                {
                    swap((j + 1) * 2 - 1, j); j = (j + 1) * 2 - 1;
                }
            }
            else
                if (arr[(j + 1) * 2] < arr[j])
                {
                    swap((j + 1) * 2, j); j = (j + 1) * 2;
                }

        }
        return peek;
    }
    int size() {
        return arr.size();
    }
    int top() {
        return arr[0];
    }

};
class maxHeap
{
    vector<int> arr;
public:
    maxHeap() {};
    int father(int i) {
        return (i - 1) / 2;
    }
    void swap(int i, int j) {
        int aux = arr[i];
        arr[i] = arr[j];
        arr[j] = aux;
    }
    void add(int i) {

        arr.push_back(i);

        int j = arr.size() - 1;
        while (j >= 0 && arr[father(j)] < arr[j])
        {

            swap(j, father(j));
            j = father(j);
        }
    }
    int peek() {
        int peek = arr[0];     if (arr.size() == 1) return peek;
        swap(0, arr.size() - 1);

        arr.pop_back();
        int j = 0;
        while (j < arr.size() - 1 && (arr[j] < arr[(j + 1) * 2] || arr[j] < arr[(j + 1) * 2 - 1]) && (j + 1) * 2 <= arr.size() - 1) {

            if (arr[(j + 1) * 2] < arr[(j + 1) * 2 - 1]) {
                if (arr[(j + 1) * 2 - 1] > arr[j])
                {
                    swap((j + 1) * 2 - 1, j); j = (j + 1) * 2 - 1;

                }
            }
            else
                if (arr[(j + 1) * 2] > arr[j])
                {
                    swap((j + 1) * 2, j); j = (j + 1) * 2;
                }

        }
        return peek;
    }
    void print() {
        for (auto i : arr)
            std::cout << i << " ";
    }
    int size() {
        return arr.size();
    }
    int top() {
        return arr[0];
    }
};
class dataStructure {
    minHeap x;
    maxHeap y;
public:
    dataStructure() {};
    bool empty() {

        return x.size() && y.size();
    }
    void add(int i) {
        if (y.size() == 0 || i < y.top())
        {
            y.add(i);
        }
        else { x.add(i); }
        if (x.size() > y.size() + 1)
        {
            y.add(x.top());
            x.peek();
        }
        else if (y.size() > x.size() + 1)
        {
            x.add(y.top());
            y.peek();
        }
    }
    int next() {

        if (x.size() > y.size())
            return  x.peek();
        else return y.peek();

    }
};

/////////////////////////////////////////////////











////////////////////////////////////////////////
// int partition(std::vector<int>& arr, int l, int r)
// {
//           int pivot = arr[r];
//           int i = l;
//           for (int j = l; j < r; j++)
//           {
//                     if (arr[j] < pivot)
//                     {
//                               std::swap(arr[i], arr[j]);
//                               i++;
//                     }
//           }
//           std::swap(arr[i], arr[r]);
//           return i;
// }

// int quickselect(std::vector<int>& arr, int l, int r, int k)
// {
//           if (l <= r)
//           {
//                     int p = partition(arr, l, r);
//                     if (p == k)
//                               return arr[p];
//                     else if (p > k)
//                               return quickselect(arr, l, p - 1, k);
//                     else
//                               return quickselect(arr, p + 1, r, k);
//           }
//           return -1;
// }
/////////////////////////////////////////////////////////////////////
typedef struct BinaryTree {
    int value;
    struct BinaryTree* tata;
    struct BinaryTree* stinga;
    struct BinaryTree* dreapta;
} BinaryTree;
void DFS(BinaryTree* T, vector<BinaryTree*>& aux) {


    if (T->stinga != nullptr)
    {

        DFS(T->stinga, aux);
    }
    if (T->dreapta)
    {
        DFS(T->dreapta, aux);
    }
    aux.push_back(T);
}

int sum(BinaryTree* T, vector<int>& sumV) {
    if (T->dreapta == nullptr && T->stinga == nullptr)
    {
        sumV.push_back(T->value);  return T->value;
    }
    else    if (T->stinga == nullptr)
    {
        int suma = sum(T->dreapta, sumV) + T->value;
        sumV.push_back(suma);
        return suma;
    }
    else   if (T->dreapta == nullptr)
    {
        int suma = sum(T->stinga, sumV) + T->value;
        sumV.push_back(suma);
        return suma;
    }

    else {
        int st = sum(T->stinga, sumV);int dr = sum(T->dreapta, sumV);

        int suma = st + dr + T->value;
        sumV.push_back(suma);
        return suma;
    }



}
vector<int> sumOfSubtree(BinaryTree* T) {
    vector<int> sumaV; sum(T, sumaV);
    return sumaV;
};
BinaryTree* makeNode(BinaryTree* father, int value) {
    BinaryTree* aux = new BinaryTree();
    aux->value = value;
    aux->dreapta = nullptr;
    aux->stinga = nullptr;
    aux->tata = father;
    return aux;

}
int sumOfInterval(BinaryTree* T, int x, int y, vector<int>& sum) {
    static int i = 0;
    if (T->dreapta == nullptr && T->stinga == nullptr) {

        if (T->value >= x && T->value <= y) return y;
        else return 0;
    }
}
//////////////////////////////////////////////////////////////////
int partion(vector<int>& a, int left, int right, int pivot) {
    int pivotValue = a[right];
    // std::swap(a[right], a[pivotValue]);
    int parIndex = left;
    for (int i = left; i < right;i++)
    {
        if (a[i] < pivotValue)
        {
            std::swap(a[i], a[parIndex]);
            parIndex++;
        }
    }
    std::swap(a[right], a[parIndex]);
    return parIndex;

}

int kth(vector<int>& a, int left, int right, int k) {
    if (k > a.size() - 1 || k < 0) return -1;
    if (left == right)
        return a[left];

    int pivotIndex = left + rand() % (right - left + 1);

    pivotIndex = partion(a, left, right, pivotIndex);

    if (pivotIndex == k) return a[pivotIndex];

    else if (pivotIndex > k) kth(a, left, pivotIndex - 1, k);

    else kth(a, pivotIndex + 1, right, k);

};

int partition(vector<int>& a, int left, int right, int partitionIndex) {
    int partitionValue = a[right];
    int storeIndex = left;

    if (right - left == 1) {
        if (a[left] > a[right])
            swap(a[left], a[right]);
        return left;
    }

    for (int i = left; i < right; i++)
    {
        if (a[i] < partitionValue)
        {

            swap(a[i], a[storeIndex]);
            storeIndex++;
        }
    }

    swap(a[storeIndex], a[right]);
    return storeIndex;

};

int kthElement(vector<int>& a, int left, int right, int k) {
    int partitionIndex = left + rand() % (right - left + 1);

    if (left == right) return a[left];
    partitionIndex = partition(a, left, right, partitionIndex);

    if (partitionIndex == k - 1) return a[partitionIndex];
    else if (partitionIndex > k) kthElement(a, left, partitionIndex - 1, k);
    else kthElement(a, partitionIndex + 1, right, k);
    return -1;
}





#include <algorithm>
int main()
{
    srand(time(NULL));
    // dataStructure x;
    // x.add(2);
    // x.add(3);
    // x.add(1);
    // x.next();
    // x.next();
    // cout << x.next();
    // vector<int> y = { 1,2,3,4,5,6,7,8 };
    // while (1) {

    //           int i;
    //           cin >> i;
    //           cout << kth(y, 0, y.size() - 1, i) << endl;
    // }

    // BinaryTree* root = makeNode(nullptr, 1);
    // root->stinga = makeNode(root, 2);
    // root->dreapta = makeNode(root, 3);
    // root->dreapta->dreapta = makeNode(root->dreapta, 7);
    // root->stinga->stinga = makeNode(root->stinga, 4);
    // root->stinga->dreapta = makeNode(root->stinga, 5);
    // vector<BinaryTree*> aux; DFS(root, aux);
    // vector<int> suma = sumOfSubtree(root);
    // for (auto i : aux)
    //           cout << i->value << " ";
    // cout << endl;
    // for (auto i : suma)
    //           cout << i << " ";
    // class myOBject {
    // public:myOBject(int i = 1) { x = i; }; int x;
    // };
    // vector <myOBject> x = { {3}, {4}, {1}, {10} };
    // std::sort(x.begin(), x.end(), [](myOBject a, myOBject b) {
    //           return a.x > b.x;
    //           });
    // for (auto j : x) {
    //           cout << j.x << " ";
    // }

    vector<int> a = { 1,2,3,4,5,6,7,8,9 };
    int i;
    while (1) {
        cin >> i;
        cout << kthElement(a, 0, a.size() - 1, i);
    }
}








