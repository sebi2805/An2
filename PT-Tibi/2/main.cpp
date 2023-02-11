#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;
struct node
{
          int value;
          node *st, *dr;
};
node *createNode(int i)
{
          node *p = new node;
          p->value = i;
          p->st = nullptr;
          p->dr = nullptr;
          return p;
}

void DFS(node *root, vector<node *> &DFSV)
{
          if (root == nullptr)
                    return;

          DFSV.push_back(root);
          if (root->st != nullptr && root->dr != nullptr)
          {
                    DFS(root->st, DFSV);
                    DFS(root->dr, DFSV);
          }
          else if (root->st != nullptr)
          {
                    DFS(root->st, DFSV);
          }
          else if (root->dr != nullptr)
          {
                    DFS(root->dr, DFSV);
          }
          else
                    return;
}

int computeSize(node *root, vector<int> &sum)
{
          if (root == nullptr)
                    return 0;

          if (root->st != nullptr && root->dr != nullptr)
          {
                    int st = computeSize(root->st, sum);
                    int dr = computeSize(root->dr, sum);
                    sum.push_back(st + dr + 1);
          }
          else if (root->st != nullptr)
          {
                    int st = computeSize(root->st, sum);
                    sum.push_back(st + 1);
          }

          else if (root->dr != nullptr)
          {

                    int dr = computeSize(root->dr, sum);
                    sum.push_back(dr + 1);
          }
          else
          {
                    sum.push_back(1);
                    return 1;
          }
}

bool computeIsBST(node *root, vector<bool> &isBST)
{
          if (root == nullptr)
                    return true;
          if (root->st != nullptr && root->dr != nullptr)
          {
                    bool st = computeIsBST(root->st, isBST); // verificam daca arborele din dreapta si din stanga este search tree
                    bool dr = computeIsBST(root->dr, isBST);
                    isBST.push_back(root->st->value < root->value && root->dr->value > root->value && st && dr);
                    return root->st->value < root->value && root->dr->value > root->value && st && dr;
                    // toata conditia trb sa fie true
          }
          else if (root->st != nullptr)
          {

                    // avem arbore doar in stanga, in dreapta nu avem ce sa verificam si ne ar crapa daca comparam nullptr
                    bool st = computeIsBST(root->st, isBST);
                    isBST.push_back(root->st->value < root->value && st);
                    return root->st->value < root->value && st;
          }
          else if (root->dr != nullptr)
          {

                    // avem arbore doar in stanga, in dreapta nu avem ce sa verificam si ne ar crapa daca comparam nullptr
                    bool dr = computeIsBST(root->dr, isBST);
                    isBST.push_back(root->dr->value < root->value && dr);
                    return root->dr->value > root->value && dr;
          }
          else
          {
                    isBST.push_back(true);
                    return true;
          } // daca e frunza e sigur SearchTree
}
map<node *, int> heights;
bool computeIsAVL(node *root, vector<bool> &isAvl)
{

          if (root == nullptr)
                    return true;
          else if (root->st != nullptr && root->dr != nullptr)
          {
                    bool st = computeIsAVL(root->st, isAvl);
                    bool dr = computeIsAVL(root->dr, isAvl);
                    heights[root] = heights[root->st] < heights[root->dr] ? heights[root->st] + 1 : heights[root->dr] + 1;
                    isAvl.push_back(st && dr && abs(heights[root->st] - heights[root->dr]) <= 1);
                    return st && dr && abs(heights[root->st] - heights[root->dr]) <= 1;
          }
          else if (root->st != nullptr)
          {
                    bool st = computeIsAVL(root->st, isAvl);

                    heights[root] = heights[root->st] + 1;
                    isAvl.push_back(st);
                    return st;
          }
          else if (root->dr != nullptr)
          {

                    bool dr = computeIsAVL(root->dr, isAvl);
                    heights[root] = heights[root->dr] + 1;
                    isAvl.push_back(dr);
                    return dr;
          }
          else
          {
                    heights[root] = 1;
                    return true;
          }
}
int biggestSearchTree(node *root)
{

          vector<int>
              sizes;
          vector<bool> isBST;

          computeIsBST(root, isBST);
          computeSize(root, sizes);

          int maxSize = -1;
          for (int i = 0; i < sizes.size(); i++)
          {
                    if (sizes[i] > maxSize && isBST[i])
                              maxSize = sizes[i];
          }
          return maxSize;
}
bool hasExactElements(vector<int> &u, vector<int> &v)
{
          map<int, int> u1, v1;
          for (auto i : u)
          {
                    if (!u1[i])
                              u1[i] = 1;
                    else
                              u1[i]++;
          }
          for (auto i : v)
          {
                    if (!v1[i])
                              v1[i] = 1;
                    else
                              v1[i]++;
          }
          bool isExact = true;
          for (auto i : u)
                    if (u1[i] != v1[i])
                              isExact = false;
          for (auto i : v)
                    if (u1[i] != v1[i])
                              isExact = false;
          return isExact;
}
int main()
{
          // node *root = createNode(2);
          // root->st = createNode(1);
          // root->dr = createNode(1);

          // cout << biggestSearchTree(root);

          // vector<int> u = {1, 1, 2, 3}, v = {1, 1, 2, 3};
          // cout << hasExactElements(u, v);
}
// 1 2 3 4 5 v

// 1 3 6 10 15 sum
// 1 2 6 24 120 prod

// 24/6*3 = 12
// 10-6+3=7

// sum[j]-sum[i]+v[i]