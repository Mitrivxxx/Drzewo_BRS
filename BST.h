#pragma once
#ifndef BST_H
#define BST_H
class BST {
private:
    struct Node {
        Node* p;        // WskaŸnik na rodzica
        Node* left;     // WskaŸnik na lewego potomka
        Node* right;    // WskaŸnik na prawego potomka
        int key;        // Klucz (wartoœæ wêz³a)

        // Konstruktor dla u³atwienia inicjalizacji wêz³ów
        Node(int k) : p(nullptr), left(nullptr), right(nullptr), key(k) {}
    };
    BST();

public:
    // Konstruktor drzewa BST


    // Funkcja dodaj¹ca element do drzewa


    //Funkcja usuwaj¹ca element

    //Funkcja szukajaca drogi do podaniego elementu

    //niewiem o co chodzi

    //Zapisz do pliku txt drzewo



    // Funkcja wyœwietlaj¹ca drzewo w porz¹dku inorder
    void inorder(Node* root);

};

#endif // BST_H
