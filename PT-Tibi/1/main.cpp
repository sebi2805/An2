#include <iostream>
#include <set>
#include <map>
using namespace std;

///  ///////////////////////////1/
class myDataStructure
{
          set<int, greater<int>> s;

public: // are default constructor
          void insert(int);
          int min();
          int max();
          int size();
          void deleteX(int);
};

void myDataStructure::insert(int i)
{

          s.insert(i);
};
int myDataStructure::min()
{

          return *s.begin();
};
int myDataStructure::max()
{
          return *s.rbegin();
};
int myDataStructure::size()
{
          return s.size();
};
void myDataStructure::deleteX(int i)
{
          s.erase(s.find(i));
}
struct Node
{
          int value;
          Node *left, *right;
};
Node *createNode(int i)
{
          Node *p = new Node;
          p->value = i;
          p->left = nullptr;
          p->right = nullptr;
          return p;
}

bool isSearchTree(Node *T) // am inlocuit eu putin ca ma enerva sa scriu
{

          // DFS
          if (T == nullptr)
                    return true;
          if (T->left != nullptr && T->right != nullptr)
          {
                    bool left = isSearchTree(T->left); // verificam daca arborele din dreapta si din stanga este search tree
                    bool right = isSearchTree(T->right);
                    return T->left->value < T->value && T->right->value > T->value && left && right;
                    // toata conditia trb sa fie true
          }
          else if (T->left != nullptr)
          {

                    // avem arbore doar in stanga, in dreapta nu avem ce sa verificam si ne ar crapa daca comparam nullptr
                    bool left = isSearchTree(T->left);
                    return T->left->value < T->value && left;
          }
          else if (T->right != nullptr)
          {

                    // avem arbore doar in stanga, in dreapta nu avem ce sa verificam si ne ar crapa daca comparam nullptr
                    bool right = isSearchTree(T->right);
                    return T->right->value > T->value && left;
          }
          else
                    return true; // daca e frunza e sigur SearchTree
}
map<Node *, int> heights;
bool isAVL(Node *root) // avl = arbore cu inaltime echilibrata
{                      // TRB SA CALCULAM INALTIMILE, FIE MAI FACEM CEVA PROGRAM, FIE MODIFICAM PUTIN STRUCTURA, Sau folosim un hashtable
          if (root == nullptr)
                    return true;
          else if (root->left != nullptr && root->right != nullptr)
          {
                    bool left = isAVL(root->left);
                    bool right = isAVL(root->right);
                    heights[root] = heights[root->left] < heights[root->right] ? heights[root->left] + 1 : heights[root->right] + 1;
                    return left && right && abs(heights[root->left] - heights[root->right]) <= 1;
          }
          else if (root->left != nullptr)
          {
                    bool left = isAVL(root->left);

                    heights[root] = heights[root->left] + 1;
                    return left;
          }
          else if (root->right != nullptr)
          {

                    bool right = isAVL(root->right);
                    heights[root] = heights[root->right] + 1;
                    return right;
          }
          else
          {
                    heights[root] = 1;
                    return true;
          }
}

void findFloor(Node *root, int x, int &value)
{
          if (root == nullptr)
                    return;
          if (root->value == x)
                    value = root->value;
          if (root->left != nullptr && x < root->value)
          {
                    findFloor(root->left, x, value);
          }
          else if (root->right != nullptr && x > root->value)
          {
                    cout << "sebi" << root->value << endl;
                    value = root->right->value;
                    findFloor(root->left, x, value);
          }
          else
                    return;
}
int floor(Node *root, int x)
{
          int floorOfX;
          findFloor(root, x, floorOfX);
          return floorOfX;
}

int max = 0;
void range(Node *root, int x, int y)
{

          if (root == nullptr || ::max > 5)
                    return;

          if (root->value < y && root->value > x)
          {
                    cout << root->value << " ";
                    ::max++;
          }
          if (root->value > y)
                    range(root->left, x, y);
          else if (root->value < x)
                    range(root->right, x, y);
          else
          {
                    range(root->left, x, y);
                    range(root->right, x, y);
          }
}
int main()
{
          Node *root = createNode(2);
          root->left = createNode(1);
          root->right = createNode(3);

          // if (isSearchTree(root))
          //           cout << "Da";
          // else

          //           cout << "Nu";

          // root->left->left = createNode(10);
          // root->left->left->left = createNode(5);
          // root->left->left->left->left = createNode(9);
          // if (isAVL(root))
          //           cout << "Da";
          // else

          //           cout << "Nu";

          // cout << floor(root, 6);

          // range(root, 0, 4);
          map<int, int> sebi;
          sebi[1] = 2;
          cout << sebi[1];
}