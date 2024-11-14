#include "pch.h"
#include "BST.h"
#include "iostream"

using namespace std;

//jakas zmiana
//jakas zmiana na dev 



int main() {
    BST tree;

    // Dodajemy elementy do drzewa
    tree.add(11);
    tree.add(53);
    tree.add(12);
    tree.add(1);
    tree.add(3);

    // Wyświetlenie drzewa w porządku inorder
    cout << "BST in-order: ";
    tree.displayInOrder();

    return 0;
}
