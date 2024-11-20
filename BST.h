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
    Node* root;     //wskaznik na korzen drzewa

    Node* insert(Node* current, int key);       //dodaj do drzewa
    Node* remove(Node* current, int key); // Rekurencyjna funkcja usuwania
    Node* findMin(Node* current);
    void removeTree(Node* current); // usun cale drzewo

    
    //ukladanie drzewa
    void inorder(Node* root);
    void preorder(Node* current);
    void postorder(Node* current);
    
public:
    // Konstruktor i destruktor
    BST();
    ~BST();
    // Funkcja dodaj�ca element do drzewa
    void insert(int key);

    //Funkcja usuwaj�ca element
    void remove(int key);
    void removeTree();
    //Funkcja szukajaca drogi do podaniego elementu

    //niewiem o co chodzi

    //Zapisz do pliku txt drzewo



    // Funkcja wy�wietlaj�ca drzewo w porz�dku inorder
    void show_inorder();
    void show_preorder();
    void show_postorder();


};

#endif // BST_H
