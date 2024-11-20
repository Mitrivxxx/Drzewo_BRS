#include "pch.h"
#include "BST.h"
#include "iostream"

using namespace std;

//jakas zmiana
//jakas zmiana na dev 



int main() {
    BST tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);

    tree.show_inorder();
    tree.show_postorder();
    tree.show_preorder();


    return 0;
}
