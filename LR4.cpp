#include <iostream>
#include "Tree.cpp"
using namespace std;

int linear_search(int* , int, int); // линейный поиск
int binary_search(int* , int, int); // двоичный поиск
void printTree(Tree<int>);

int main(int argc, char* argv[])
{
    int a[] = {1, 5, 2, 4, 3, 7, 3, 8};
    int b[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int len = sizeof(a) / sizeof(int);
    cout << "Element " << a[4] << " has index: " << linear_search(a, len, a[4]) << endl;
    cout << "Element " << b[4] << " has index: " << binary_search(b, len, b[4]) << endl;

    Tree<int> tree;
    
    tree.insert(12);
    tree.insert(3);
    tree.insert(1);
    tree.insert(10);
    tree.insert(7);
    tree.insert(20);
    tree.insert(15);

    tree.insert(17);
    tree.insert(5);
    tree.insert(9);

    printTree(tree);
    
    cout << "tree max value is: " << tree.max() << '\n';
    cout << "tree min value is: " << tree.min() << '\n';

    tree.remove(5);
    tree.remove(10);
    tree.remove(12);

    cout << "Next number after " << 3 << " is: " << tree.next(3) << '\n';
    
    printTree(tree);

    tree.clear();
}

// линейный поиск
int linear_search(int* a, int len, int x)
{
    for (int i = 0; i < len; i++)
        if (a[i] == x)
            return i;
    cout << "Can't find your element\n";
    return -1;
}

// двоичный поиск
int binary_search(int* a, int len, int x)
{
    int l = -1;
    int r = len;
    //int m;
    
    while (r > l + 1)
    {
        int m = (l + r) / 2;
        if (a[m] < x)
            l = m;
        else
            r = m;
    }

    if (r < len && a[r] == x)
        return r;
    else
    {
        cout << "Can't find your element\n";
        return -1;
    }
}

// Печать элементов дерева
void printTree(Tree<int> tree)
{
    for (int i = tree.min(); i != tree.max(); i = tree.next(i))
    {
        cout << i << '\t';
    }
    cout << tree.max() << '\n';
}