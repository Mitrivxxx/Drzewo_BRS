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
    // Funkcja dodaj¹ca element do drzewa
    void insert(int key);

    //Funkcja usuwaj¹ca element
    void remove(int key);
    void removeTree();
    //Funkcja szukajaca drogi do podaniego elementu

    //niewiem o co chodzi

    //Zapisz do pliku txt drzewo



    // Funkcja wyœwietlaj¹ca drzewo w porz¹dku inorder
    void show_inorder();
    void show_preorder();
    void show_postorder();


};

#endif // BST_H
