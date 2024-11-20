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
        return new Node(key); // Tworzymy nowy wêze³
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

    return current; // Zwracamy bie¿¹cy wêze³
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
        cout << current->key << " "; // Przetwórz bie¿¹cy wêze³
        preorder(current->left);    // PrzejdŸ do lewego poddrzewa
        preorder(current->right);   // PrzejdŸ do prawego poddrzewa
    }
}

void BST::postorder(Node* current)
{
    if (current != nullptr) {
        postorder(current->left);   // PrzejdŸ do lewego poddrzewa
        postorder(current->right);  // PrzejdŸ do prawego poddrzewa
        cout << current->key << " "; // Przetwórz bie¿¹cy wêze³
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
    cout << endl; // Dodanie nowej linii po wyœwietleniu
}

void BST::show_postorder(){
    cout << "Postorder: ";
    postorder(root);
    cout << endl; // Dodanie nowej linii po wyœwietleniu
}


