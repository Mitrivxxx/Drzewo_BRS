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
//usun element z drzewa
BST::Node* BST::remove(Node* current, int key) {
    if (current == nullptr) {
        return nullptr; // Klucz nie znaleziony
    }

    if (key < current->key) {
        current->left = remove(current->left, key);
    }
    else if (key > current->key) {
        current->right = remove(current->right, key);
    }
    else {
        // Klucz znaleziony
        if (current->left == nullptr && current->right == nullptr) {
            // W�ze� jest li�ciem
            delete current;
            return nullptr;
        }
        else if (current->left == nullptr) {
            // W�ze� ma jedno dziecko (prawe)
            Node* temp = current->right;
            delete current;
            return temp;
        }
        else if (current->right == nullptr) {
            // W�ze� ma jedno dziecko (lewe)
            Node* temp = current->left;
            delete current;
            return temp;
        }
        else {
            // W�ze� ma dwoje dzieci
            Node* minNode = findMin(current->right); // Znajd� nast�pnika
            current->key = minNode->key;            // Przepisz klucz
            current->right = remove(current->right, minNode->key); // Usu� nast�pnika
        }
    }
    return current;
}
//usun cale drzewo






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



//------------------------Funkcjie pomocnicze------------------
void BST::insert(int key) {
    root = insert(root, key);
}
BST::Node* BST::findMin(Node* current) {
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

void BST::removeTree(Node* current)
{
    if (current != nullptr) {
        removeTree(current->left);  // Usu� lewe poddrzewo
        removeTree(current->right); // Usu� prawe poddrzewo
        delete current;        // Usu� bie��cy w�ze�
    }
}

//----------Funkcje publiczne ---------
void BST::show_inorder() {
    cout << "Inorder: "; 
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
void BST::remove(int key) {
    root = remove(root, key);
}

void BST::removeTree()
{
    removeTree(root);
    root = nullptr;
}


