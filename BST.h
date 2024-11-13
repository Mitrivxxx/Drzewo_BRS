#pragma once
#ifndef BST_H
#define BST_H
class BST {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;

        Node(int value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // Funkcja pomocnicza do dodawania nowego elementu
    Node* insert(Node* node, int value);

    // Funkcja pomocnicza do wyœwietlania drzewa w porz¹dku inorder
    void inorder(Node* node);

public:
    // Konstruktor drzewa BST
    BST();

    // Funkcja dodaj¹ca element do drzewa
    void add(int value);

    // Funkcja wyœwietlaj¹ca drzewo w porz¹dku inorder
    void displayInOrder();
};

#endif // BST_H
