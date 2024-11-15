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

    // Funkcja pomocnicza do wyświetlania drzewa w porządku inorder
    void inorder(Node* node);

public:
    // Konstruktor drzewa BST
    BST();

    // Funkcja dodająca element do drzewa
    void add(int value);

    // Funkcja wyświetlająca drzewo w porządku inorder
    void displayInOrder();
};

#endif // BST_H
