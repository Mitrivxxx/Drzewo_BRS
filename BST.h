/**
 * @brief Klasa reprezentuj�ca drzewo BST (Binary Search Tree).
 *
 * Klasa implementuje drzewo binarne wyszukiwania, umo�liwiaj�c dodawanie, usuwanie,
 * przeszukiwanie i zapisywanie drzewa do pliku. Operacje te s� wykonywane zgodnie z zasadami
 * drzewa BST, gdzie ka�dy w�ze� ma maksymalnie dw�ch potomk�w: lewego i prawego.
 */
class BST {
private:
    /**
     * @brief Struktura reprezentuj�ca w�ze� drzewa BST.
     *
     * Struktura zawiera wska�niki na rodzica oraz potomk�w (lewego i prawego),
     * a tak�e klucz (warto��) przechowywan� w w�le.
     */
    struct Node {
        Node* p;        ///< Wska�nik na rodzica
        Node* left;     ///< Wska�nik na lewego potomka
        Node* right;    ///< Wska�nik na prawego potomka
        int key;        ///< Klucz (warto��) przechowywana w w�le

        /**
         * @brief Konstruktor inicjalizuj�cy w�ze� z kluczem.
         *
         * Ustawia wska�niki na rodzica i potomk�w na nullptr oraz przypisuje
         * warto�� klucza.
         *
         * @param k Klucz (warto��) w�z�a.
         */
        Node(int k) : p(nullptr), left(nullptr), right(nullptr), key(k) {}
    };

    Node* root;  ///< Korze� drzewa

    /**
     * @brief Rekurencyjna funkcja dodaj�ca nowy klucz do drzewa.
     *
     * Funkcja wstawia nowy klucz do drzewa BST, zachowuj�c jego strukturaln� w�a�ciwo��.
     * @param current Wska�nik na bie��cy w�ze�.
     * @param key Klucz, kt�ry ma zosta� dodany.
     * @return Wska�nik na nowy korze� (lub pozosta�y korze�) poddrzewa.
     */
    Node* insert(Node* current, int key);

    /**
     * @brief Rekurencyjna funkcja usuwaj�ca w�ze� o danym kluczu.
     *
     * Funkcja usuwa w�ze� o zadanym kluczu z drzewa, zachowuj�c strukturaln� w�a�ciwo�� drzewa BST.
     * @param current Wska�nik na bie��cy w�ze�.
     * @param key Klucz w�z�a, kt�ry ma zosta� usuni�ty.
     * @return Wska�nik na nowy korze� (lub pozosta�y korze�) poddrzewa.
     */
    Node* remove(Node* current, int key);

    /**
     * @brief Funkcja znajduj�ca najmniejszy w�ze� w drzewie.
     *
     * Funkcja przeszukuje lewe poddrzewo, a� znajdzie w�ze� o najmniejszym kluczu.
     * @param current Wska�nik na bie��cy w�ze�.
     * @return Wska�nik na najmniejszy w�ze�.
     */
    Node* findMin(Node* current);

    /**
     * @brief Funkcja usuwaj�ca ca�e drzewo BST.
     *
     * Funkcja rekurencyjnie usuwa wszystkie w�z�y w drzewie.
     * @param current Wska�nik na bie��cy w�ze�.
     */
    void removeTree(Node* current);

    /**
     * @brief Funkcja zapisuj�ca drzewo do pliku w okre�lonym porz�dku.
     *
     * Funkcja zapisuje klucze drzewa do pliku w porz�dku zale�nym od zadanego typu.
     * @param node Wska�nik na w�ze�, kt�ry ma zosta� zapisany.
     * @param file Referencja na obiekt pliku, do kt�rego b�d� zapisywane dane.
     * @param type Typ przej�cia drzewa (1 - inorder, 2 - preorder, 3 - postorder).
     */
    void saveToFile(Node* node, std::ofstream& file, int type);

    // Funkcje przeszukiwania drzewa
    /**
     * @brief Funkcja przechodz�ca drzewo w porz�dku inorder.
     *
     * Funkcja rekurencyjnie przechodzi drzewo i wy�wietla klucze w porz�dku inorder (lewy, korze�, prawy).
     * @param root Wska�nik na korze� poddrzewa.
     */
    void inorder(Node* root);

    /**
     * @brief Funkcja przechodz�ca drzewo w porz�dku preorder.
     *
     * Funkcja rekurencyjnie przechodzi drzewo i wy�wietla klucze w porz�dku preorder (korze�, lewy, prawy).
     * @param current Wska�nik na bie��cy w�ze�.
     */
    void preorder(Node* current);

    /**
     * @brief Funkcja przechodz�ca drzewo w porz�dku postorder.
     *
     * Funkcja rekurencyjnie przechodzi drzewo i wy�wietla klucze w porz�dku postorder (lewy, prawy, korze�).
     * @param current Wska�nik na bie��cy w�ze�.
     */
    void postorder(Node* current);

public:
    /**
     * @brief Konstruktor klasy BST.
     *
     * Inicjalizuje puste drzewo (korze� ustawiony na nullptr).
     */
    BST();

    /**
     * @brief Destruktor klasy BST.
     *
     * Usuwa wszystkie w�z�y w drzewie, aby zwolni� pami��.
     */
    ~BST();

    /**
     * @brief Funkcja dodaj�ca nowy klucz do drzewa.
     *
     * Funkcja wywo�uje rekurencyjn� wersj� `insert` w celu dodania nowego klucza.
     * @param key Klucz, kt�ry ma zosta� dodany do drzewa.
     */
    void insert(int key);

    /**
     * @brief Funkcja usuwaj�ca w�ze� o danym kluczu.
     *
     * Funkcja wywo�uje rekurencyjn� wersj� `remove` w celu usuni�cia w�z�a.
     * @param key Klucz w�z�a, kt�ry ma zosta� usuni�ty.
     */
    void remove(int key);

    /**
     * @brief Funkcja usuwaj�ca ca�e drzewo.
     *
     * Funkcja wywo�uje rekurencyjn� wersj� `removeTree` w celu usuni�cia ca�ego drzewa.
     */
    void removeTree();

    /**
     * @brief Funkcja zapisuj�ca drzewo do pliku w okre�lonym porz�dku.
     *
     * Funkcja zapisuje drzewo do pliku w formacie tekstowym w zadanym porz�dku.
     * @param filename Nazwa pliku, do kt�rego drzewo zostanie zapisane.
     * @param type Typ przej�cia drzewa (1 - inorder, 2 - preorder, 3 - postorder).
     */
    void saveToFileP(const std::string& filename, int type);

    /**
     * @brief Funkcja wy�wietlaj�ca drzewo w porz�dku inorder.
     *
     * Funkcja wywo�uje rekurencyjn� funkcj� `inorder` i wypisuje elementy drzewa w porz�dku inorder.
     */
    void show_inorder();

    /**
     * @brief Funkcja wy�wietlaj�ca drzewo w porz�dku preorder.
     *
     * Funkcja wywo�uje rekurencyjn� funkcj� `preorder` i wypisuje elementy drzewa w porz�dku preorder.
     */
    void show_preorder();

    /**
     * @brief Funkcja wy�wietlaj�ca drzewo w porz�dku postorder.
     *
     * Funkcja wywo�uje rekurencyjn� funkcj� `postorder` i wypisuje elementy drzewa w porz�dku postorder.
     */
    void show_postorder();
};
