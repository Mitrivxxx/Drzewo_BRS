#include "pch.h"
#include "BST.h"
#include "iostream"

using namespace std;



BST::BST() : root(nullptr) {}

// Rekurencyjna funkcja pomocnicza do dodawania elementu
BST::Node* BST::insert(Node* node, int value) {
    if (node == nullptr) {
        return new Node(value);
    }
    if (value < node->data) {
        node->left = insert(node->left, value);
    }
    else if (value > node->data) {
        node->right = insert(node->right, value);
    }
    return node;
}

// Publiczna metoda do dodawania elementu, wywo�uj�ca metod� insert
void BST::add(int value) {
    root = insert(root, value);
}

// Rekurencyjna funkcja pomocnicza do wy�wietlania drzewa w porz�dku inorder
void BST::inorder(Node* node) {
    if (node != nullptr) {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
}

// Wy�wietla drzewo w porz�dku inorder
void BST::displayInOrder() {
    inorder(root);
    cout << endl;
}