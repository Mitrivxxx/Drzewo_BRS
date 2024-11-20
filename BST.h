#pragma once
#ifndef BST_H
#define BST_H
class BST {
private:
    struct Node {
        Node* p;        // Wska�nik na rodzica
        Node* left;     // Wska�nik na lewego potomka
        Node* right;    // Wska�nik na prawego potomka
        int key;        // Klucz (warto�� w�z�a)

        // Konstruktor dla u�atwienia inicjalizacji w�z��w
        Node(int k) : p(nullptr), left(nullptr), right(nullptr), key(k) {}
    };
    BST();

public:
    // Konstruktor drzewa BST


    // Funkcja dodaj�ca element do drzewa


    //Funkcja usuwaj�ca element

    //Funkcja szukajaca drogi do podaniego elementu

    //niewiem o co chodzi

    //Zapisz do pliku txt drzewo



    // Funkcja wy�wietlaj�ca drzewo w porz�dku inorder
    void inorder(Node* root);

};

#endif // BST_H
