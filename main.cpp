#include "pch.h"
#include "BST.h"
#include "iostream"
#include "vector"


using namespace std;



int main() {
    BST tree;
    //dodaj elementy do drzewa
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(2);
    tree.insert(8);
    tree.insert(9);
    tree.insert(4);
    //pokaz
    tree.show_inorder();
    tree.show_postorder();
    tree.show_preorder();
    //usun
    cout <<"\nUsuwanie elementu po wartosci z drzewa"<< endl;
    tree.remove(1);
    tree.remove(2);
    tree.remove(3);
    tree.show_inorder();
    cout << "\nUsun cale drzwo" << endl;
    tree.removeTree();
    tree.show_inorder();


    return 0;
}
