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
            // Wêze³ jest liœciem
            delete current;
            return nullptr;
        }
        else if (current->left == nullptr) {
            // Wêze³ ma jedno dziecko (prawe)
            Node* temp = current->right;
            delete current;
            return temp;
        }
        else if (current->right == nullptr) {
            // Wêze³ ma jedno dziecko (lewe)
            Node* temp = current->left;
            delete current;
            return temp;
        }
        else {
            // Wêze³ ma dwoje dzieci
            Node* minNode = findMin(current->right); // ZnajdŸ nastêpnika
            current->key = minNode->key;            // Przepisz klucz
            current->right = remove(current->right, minNode->key); // Usuñ nastêpnika
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
        removeTree(current->left);  // Usuñ lewe poddrzewo
        removeTree(current->right); // Usuñ prawe poddrzewo
        delete current;        // Usuñ bie¿¹cy wêze³
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
    cout << endl; // Dodanie nowej linii po wyœwietleniu
}

void BST::show_postorder(){
    cout << "Postorder: ";
    postorder(root);
    cout << endl; // Dodanie nowej linii po wyœwietleniu
}
void BST::remove(int key) {
    root = remove(root, key);
}

void BST::removeTree()
{
    removeTree(root);
    root = nullptr;
}


