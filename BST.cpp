#include "pch.h"
#include "BST.h"
#include <iostream>

#include <fstream>
#include <string>
using namespace std;


// Konstruktor klasy BST
/**
 * @brief Konstruktor domyslny klasy BST.
 *
 * Inicjalizuje korzen drzewa jako `nullptr`.
 */
BST::BST() : root(nullptr) {}

/**
 * @brief Destruktor klasy BST.
 *
 * Niszczy drzewo. Upewnia sie, ze wszystkie wezly zostaly poprawnie usuniete.
 */
BST::~BST() {}

/**
 * @brief Dodaje klucz do drzewa BST.
 *
 * Tworzy nowy wezel i wstawia go na odpowiednia pozycje w drzewie.
 *
 * @param current Wskaznik na aktualny wezel drzewa.
 * @param key Wartosc klucza do dodania.
 * @return Wskaznik na aktualny wezel po dodaniu nowego elementu.
 */


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
/**
 * @brief Usuwa wezel z drzewa BST.
 *
 * Funkcja rekursywnie przeszukuje drzewo w celu znalezienia wezla o podanym kluczu
 * i usuwa go. Usuwanie moze odbywac sie na trzy sposoby:
 * - Wezel nie ma dzieci (jest liœciem) - usuwa wezel.
 * - Wezel ma jedno dziecko (lewe lub prawe) - usuwa wezel i przypisuje odpowiednie dziecko.
 * - Wezel ma dwoje dzieci - znajduje najmniejszy wezel w prawym poddrzewie, przepisuje jego
 *   klucz do usuwanego wezla i usuwa ten najmniejszy wezel.
 *
 * @param current Wskaznik na aktualny wezel drzewa, od ktorego rozpoczyna sie przeszukiwanie.
 * @param key Klucz wezla, ktory ma zostac usuniety.
 * @return Wskaznik na aktualny wezel po usunieciu.
 */
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

/**
 * @brief Zapisuje drzewo do pliku w zadanej kolejnosci.
 *
 * Funkcja rekurencyjnie przeszukuje drzewo i zapisuje klucze wezlow do pliku w zaleznosci od typu
 * przejscia drzewa:
 * - Inorder: left, root, right
 * - Preorder: root, left, right
 * - Postorder: left, right, root
 *
 * @param node Wskaznik na obecny wezel.
 * @param file Strumien pliku, do ktorego zapisywane sa klucze wezlow.
 * @param type Typ przejscia drzewa:
 *              1 - inorder
 *              2 - preorder
 *              3 - postorder
 */
void BST::saveToFile(Node* node, std::ofstream& file, int type) {
    if (node == nullptr) {
        return;
    }

    switch (type) {
    case 1:
        // Inorder: left, root, right
        saveToFile(node->left, file, type);
        file << node->key << " ";
        saveToFile(node->right, file, type);
        break;

    case 2:
        // Preorder: root, left, right
        file << node->key << " ";
        saveToFile(node->left, file, type);
        saveToFile(node->right, file, type);
        break;

    case 3:
        // Postorder: left, right, root
        saveToFile(node->left, file, type);
        saveToFile(node->right, file, type);
        file << node->key << " ";
        break;

    default:
        cout << "Nieobs³ugiwany typ przegl¹dania drzewa!" << endl;
    }
}
void BST::saveToFileP(const std::string& filename, int type) {
    // Zapis do pliku tekstowego
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Nie mo¿na otworzyæ pliku tekstowego: " << filename << std::endl;
        return;
    }
    saveToFile(root, file, type); // Wywo³anie metody rekurencyjnej
    file.close();

    // Zapis do pliku binarnego
    std::ofstream fileBin("treeBin.bin", std::ios::binary);
    if (!fileBin.is_open()) {
        std::cerr << "Nie mo¿na otworzyæ pliku binarnego: treeBin.bin" << std::endl;
        return;
    }
    saveToBinary(root, fileBin); // Wywo³anie metody dla zapisu binarnego
    fileBin.close();
}

void BST::saveToBinary(Node* node, std::ofstream& fileBin) {
    if (node == nullptr) {
        return;
    }

    // Zapisujemy w kolejnoœci inorder (mo¿esz zmieniæ kolejnoœæ wed³ug potrzeb)
    saveToBinary(node->left, fileBin);
    fileBin.write(reinterpret_cast<const char*>(&node->key), sizeof(node->key));
    saveToBinary(node->right, fileBin);
}


//Funkcje ukladajace drzewo
// inorder
/**
 * @brief Przechodzi drzewo BST w porzadku inorder (lewy, korzen, prawy).
 *
 * Funkcja rekurencyjnie przechodzi drzewo BST w porzadku inorder, czyli najpierw przeszukuje
 * lewe poddrzewo, nastepnie wypisuje klucz wezla (korzen), a na koniec przeszukuje prawe poddrzewo.
 * Porzadek ten jest wykorzystywany m.in. do uzyskania posortowanej listy kluczy w drzewie.
 *
 * @param root Wskaznik na aktualny wezel, od ktorego rozpoczyna sie przechodzenie drzewa.
 */
void BST::inorder(Node* root)
{
    if (root != nullptr) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}
/**
 * @brief Przechodzi drzewo BST w porzadku preorder (korzen, lewy, prawy).
 *
 * Funkcja rekurencyjnie przechodzi drzewo BST w porzadku preorder, czyli najpierw wypisuje
 * klucz wezla (korzen), nastepnie przeszukuje lewe poddrzewo, a na koniec prawe poddrzewo.
 *
 * @param current Wskaznik na aktualny wezel, od ktorego rozpoczyna sie przechodzenie drzewa.
 */
void BST::preorder(Node* current)
{
    if (current != nullptr) {
        cout << current->key << " ";
        preorder(current->left);
        preorder(current->right);
    }
}
/**
 * @brief Przechodzi drzewo BST w porzadku postorder (lewy, prawy, korzen).
 *
 * Funkcja rekurencyjnie przechodzi drzewo BST w porzadku postorder, czyli najpierw przeszukuje
 * lewe poddrzewo, potem prawe poddrzewo, a na koniec wypisuje klucz wezla (korzen).
 *
 * @param current Wskaznik na aktualny wezel, od ktorego rozpoczyna sie przechodzenie drzewa.
 */
void BST::postorder(Node* current)
{
    if (current != nullptr) {
        postorder(current->left);
        postorder(current->right);
        cout << current->key << " ";
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
/**
 * @brief Usuwa cale drzewo BST.
 *
 * Funkcja usuwa cale drzewo BST, usuwajac wszystkie wezly i resetujac korzen drzewa.
 */
void BST::removeTree(Node* current)
{
    if (current != nullptr) {
        removeTree(current->left);  // Usuñ lewe poddrzewo
        removeTree(current->right); // Usuñ prawe poddrzewo
        delete current;        // Usuñ bie¿¹cy wêze³
    }
}
/**
 * @brief Wyswietla drzewo w porzadku inorder.
 *
 * Funkcja wypisuje wszystkie klucze w drzewie w porzadku inorder (lewy, korzen, prawy).
 * Jest to jeden ze sposobow przechodzenia drzewa, ktory daje posortowane elementy.
 */
//----------Funkcje publiczne ---------
void BST::show_inorder() {
    cout << "Inorder: "; 
    inorder(root);
    cout << endl;
}
/**
 * @brief Wyswietla drzewo w porzadku preorder.
 *
 * Funkcja wypisuje wszystkie klucze w drzewie w porzadku preorder (korzen, lewy, prawy).
 * Jest to inny sposob przechodzenia drzewa, w ktorym najpierw przetwarzamy korzen.
 */
void BST::show_preorder(){
    cout << "Preorder: ";
    preorder(root);
    cout << endl; // Dodanie nowej linii po wyœwietleniu
}
/**
 * @brief Wyswietla drzewo w porzadku postorder.
 *
 * Funkcja wypisuje wszystkie klucze w drzewie w porzadku postorder (lewy, prawy, korzen).
 * Jest to sposób przechodzenia drzewa, w którym najpierw przetwarzamy dzieci przed rodzicem.
 */
void BST::show_postorder(){
    cout << "Postorder: ";
    postorder(root);
    cout << endl; // Dodanie nowej linii po wyœwietleniu
}
/**
 * @brief Usuwa wezel z drzewa BST.
 *
 * Funkcja usuwa wezel o zadanym kluczu z drzewa. W przypadku znalezienia wezla,
 * zostaje on usuniety, a drzewo zostaje odpowiednio zaktualizowane.
 *
 * @param key Klucz wezla, ktory ma zostac usuniety.
 */
void BST::remove(int key) {
    root = remove(root, key);
}

void BST::removeTree()
{
    removeTree(root);
    root = nullptr;
}

