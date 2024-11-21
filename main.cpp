#include "pch.h"
#include "BST.h"
#include "iostream"
#include "vector"
#include <fstream> // Potrzebne do obsługi plików
#include <string>

using namespace std;

//to jest kod osoby 1
//funkcja 1
//funkcja 2
//funkcja 3

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
    cout << "Drzewo zostalo usuniete" << endl;
    tree.show_inorder();
    cout << endl;
    //zapisz do pliku
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(2);
    tree.insert(8);
    tree.insert(9);
    tree.insert(4);
    int type = 0;
    cout << "Wybierz metode zapisu do pliku: \n1-inorder\n2-preorder\n3-postorder" << endl;
    cout << "Wybrano: "; cin >> type;

    tree.saveToFileP("tree.txt", type);
    switch (type)
    {
    case 1:
        cout << "\nZapisano metoda inorder. ";
        break;
    case 2:
        cout << "\nZapisano metoda preorder. ";
        break;
    case 3:
        cout << "\nZapisano metoda postorder. ";
        break;
    default:
        cout << "\nBlad";
        break;
    }

    return 0;
}
