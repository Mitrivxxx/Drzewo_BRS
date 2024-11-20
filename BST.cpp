#include "pch.h"
#include "BST.h"
#include "iostream"

using namespace std;


// Konstruktor klasy BST
BST::BST() : root(nullptr) {}

// Destruktor klasy BST
BST::~BST() {}


// dodaj do drzewa
BST::Node* BST::insert(Node* current, int key) {
    if (current == nullptr) {
        return new Node(key); // Tworzymy nowy w�ze�
    }

    if (key < current->key) {
        Node* leftChild = insert(current->left, key);
        current->left = leftChild;
        leftChild->p = current; // Ustawiamy rodzica
    }
    else if (key > current->key) {
        Node* rightChild = insert(current->right, key);
        current->right = rightChild;
        rightChild->p = current; // Ustawiamy rodzica
    }

    return current; // Zwracamy bie��cy w�ze�
}


//Funkcje ukladajace drzewo
// inorder
void BST::inorder(Node* root)
{
    if (root != nullptr) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}
void BST::preorder(Node* current)
{
    if (current != nullptr) {
        cout << current->key << " "; // Przetw�rz bie��cy w�ze�
        preorder(current->left);    // Przejd� do lewego poddrzewa
        preorder(current->right);   // Przejd� do prawego poddrzewa
    }
}

void BST::postorder(Node* current)
{
    if (current != nullptr) {
        postorder(current->left);   // Przejd� do lewego poddrzewa
        postorder(current->right);  // Przejd� do prawego poddrzewa
        cout << current->key << " "; // Przetw�rz bie��cy w�ze�
    }
}



//Funkcjie pomocnicze
void BST::insert(int key) {
    cout << "Inorder: ";
    root = insert(root, key);
}


//ukladanie drzewa
void BST::show_inorder() {
    inorder(root);
    cout << endl;
}
void BST::show_preorder(){
    cout << "Preorder: ";
    preorder(root);
    cout << endl; // Dodanie nowej linii po wy�wietleniu
}

void BST::show_postorder(){
    cout << "Postorder: ";
    postorder(root);
    cout << endl; // Dodanie nowej linii po wy�wietleniu
}


