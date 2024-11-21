/**
 * @brief Klasa reprezentuj¹ca drzewo BST (Binary Search Tree).
 *
 * Klasa implementuje drzewo binarne wyszukiwania, umo¿liwiaj¹c dodawanie, usuwanie,
 * przeszukiwanie i zapisywanie drzewa do pliku. Operacje te s¹ wykonywane zgodnie z zasadami
 * drzewa BST, gdzie ka¿dy wêze³ ma maksymalnie dwóch potomków: lewego i prawego.
 */
class BST {
private:
    /**
     * @brief Struktura reprezentuj¹ca wêze³ drzewa BST.
     *
     * Struktura zawiera wskaŸniki na rodzica oraz potomków (lewego i prawego),
     * a tak¿e klucz (wartoœæ) przechowywan¹ w wêŸle.
     */
    struct Node {
        Node* p;        ///< WskaŸnik na rodzica
        Node* left;     ///< WskaŸnik na lewego potomka
        Node* right;    ///< WskaŸnik na prawego potomka
        int key;        ///< Klucz (wartoœæ) przechowywana w wêŸle

        /**
         * @brief Konstruktor inicjalizuj¹cy wêze³ z kluczem.
         *
         * Ustawia wskaŸniki na rodzica i potomków na nullptr oraz przypisuje
         * wartoœæ klucza.
         *
         * @param k Klucz (wartoœæ) wêz³a.
         */
        Node(int k) : p(nullptr), left(nullptr), right(nullptr), key(k) {}
    };

    Node* root;  ///< Korzeñ drzewa

    /**
     * @brief Rekurencyjna funkcja dodaj¹ca nowy klucz do drzewa.
     *
     * Funkcja wstawia nowy klucz do drzewa BST, zachowuj¹c jego strukturaln¹ w³aœciwoœæ.
     * @param current WskaŸnik na bie¿¹cy wêze³.
     * @param key Klucz, który ma zostaæ dodany.
     * @return WskaŸnik na nowy korzeñ (lub pozosta³y korzeñ) poddrzewa.
     */
    Node* insert(Node* current, int key);

    /**
     * @brief Rekurencyjna funkcja usuwaj¹ca wêze³ o danym kluczu.
     *
     * Funkcja usuwa wêze³ o zadanym kluczu z drzewa, zachowuj¹c strukturaln¹ w³aœciwoœæ drzewa BST.
     * @param current WskaŸnik na bie¿¹cy wêze³.
     * @param key Klucz wêz³a, który ma zostaæ usuniêty.
     * @return WskaŸnik na nowy korzeñ (lub pozosta³y korzeñ) poddrzewa.
     */
    Node* remove(Node* current, int key);

    /**
     * @brief Funkcja znajduj¹ca najmniejszy wêze³ w drzewie.
     *
     * Funkcja przeszukuje lewe poddrzewo, a¿ znajdzie wêze³ o najmniejszym kluczu.
     * @param current WskaŸnik na bie¿¹cy wêze³.
     * @return WskaŸnik na najmniejszy wêze³.
     */
    Node* findMin(Node* current);

    /**
     * @brief Funkcja usuwaj¹ca ca³e drzewo BST.
     *
     * Funkcja rekurencyjnie usuwa wszystkie wêz³y w drzewie.
     * @param current WskaŸnik na bie¿¹cy wêze³.
     */
    void removeTree(Node* current);

    /**
     * @brief Funkcja zapisuj¹ca drzewo do pliku w okreœlonym porz¹dku.
     *
     * Funkcja zapisuje klucze drzewa do pliku w porz¹dku zale¿nym od zadanego typu.
     * @param node WskaŸnik na wêze³, który ma zostaæ zapisany.
     * @param file Referencja na obiekt pliku, do którego bêd¹ zapisywane dane.
     * @param type Typ przejœcia drzewa (1 - inorder, 2 - preorder, 3 - postorder).
     */
    void saveToFile(Node* node, std::ofstream& file, int type);

    // Funkcje przeszukiwania drzewa
    /**
     * @brief Funkcja przechodz¹ca drzewo w porz¹dku inorder.
     *
     * Funkcja rekurencyjnie przechodzi drzewo i wyœwietla klucze w porz¹dku inorder (lewy, korzeñ, prawy).
     * @param root WskaŸnik na korzeñ poddrzewa.
     */
    void inorder(Node* root);

    /**
     * @brief Funkcja przechodz¹ca drzewo w porz¹dku preorder.
     *
     * Funkcja rekurencyjnie przechodzi drzewo i wyœwietla klucze w porz¹dku preorder (korzeñ, lewy, prawy).
     * @param current WskaŸnik na bie¿¹cy wêze³.
     */
    void preorder(Node* current);

    /**
     * @brief Funkcja przechodz¹ca drzewo w porz¹dku postorder.
     *
     * Funkcja rekurencyjnie przechodzi drzewo i wyœwietla klucze w porz¹dku postorder (lewy, prawy, korzeñ).
     * @param current WskaŸnik na bie¿¹cy wêze³.
     */
    void postorder(Node* current);

public:
    /**
     * @brief Konstruktor klasy BST.
     *
     * Inicjalizuje puste drzewo (korzeñ ustawiony na nullptr).
     */
    BST();

    /**
     * @brief Destruktor klasy BST.
     *
     * Usuwa wszystkie wêz³y w drzewie, aby zwolniæ pamiêæ.
     */
    ~BST();

    /**
     * @brief Funkcja dodaj¹ca nowy klucz do drzewa.
     *
     * Funkcja wywo³uje rekurencyjn¹ wersjê `insert` w celu dodania nowego klucza.
     * @param key Klucz, który ma zostaæ dodany do drzewa.
     */
    void insert(int key);

    /**
     * @brief Funkcja usuwaj¹ca wêze³ o danym kluczu.
     *
     * Funkcja wywo³uje rekurencyjn¹ wersjê `remove` w celu usuniêcia wêz³a.
     * @param key Klucz wêz³a, który ma zostaæ usuniêty.
     */
    void remove(int key);

    /**
     * @brief Funkcja usuwaj¹ca ca³e drzewo.
     *
     * Funkcja wywo³uje rekurencyjn¹ wersjê `removeTree` w celu usuniêcia ca³ego drzewa.
     */
    void removeTree();

    /**
     * @brief Funkcja zapisuj¹ca drzewo do pliku w okreœlonym porz¹dku.
     *
     * Funkcja zapisuje drzewo do pliku w formacie tekstowym w zadanym porz¹dku.
     * @param filename Nazwa pliku, do którego drzewo zostanie zapisane.
     * @param type Typ przejœcia drzewa (1 - inorder, 2 - preorder, 3 - postorder).
     */
    void saveToFileP(const std::string& filename, int type);

    /**
     * @brief Funkcja wyœwietlaj¹ca drzewo w porz¹dku inorder.
     *
     * Funkcja wywo³uje rekurencyjn¹ funkcjê `inorder` i wypisuje elementy drzewa w porz¹dku inorder.
     */
    void show_inorder();

    /**
     * @brief Funkcja wyœwietlaj¹ca drzewo w porz¹dku preorder.
     *
     * Funkcja wywo³uje rekurencyjn¹ funkcjê `preorder` i wypisuje elementy drzewa w porz¹dku preorder.
     */
    void show_preorder();

    /**
     * @brief Funkcja wyœwietlaj¹ca drzewo w porz¹dku postorder.
     *
     * Funkcja wywo³uje rekurencyjn¹ funkcjê `postorder` i wypisuje elementy drzewa w porz¹dku postorder.
     */
    void show_postorder();
};
