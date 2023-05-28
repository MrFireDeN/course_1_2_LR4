#include <cstdlib>

template <class T>
class Tree 
{
private:
    // Элемент дерева
    struct Node
    {
        Node* parent; // родитель
        Node* left; // левый ребонок
        Node* right; // правый ребонок
        T key; // значение элемента
    };
    
    Node* head = nullptr; // корень дерева
    int len = 0; // длина дерева

    // Поиск элемента
    Node* search(T x)
    {
        if (len == 0)
            return nullptr;
        
        Node* n = head;

        do
        {
            if (x == n->key)
                return n;
            
            if (x < n->key)
                n = n->left;
            else
                n = n->right;
        }
        while (n != nullptr);

        return n;
    }
    
    // Минимальный элемент
    Node* minimum(Node* x)
    {
        if (len == 0)
            return nullptr;

        while (x->left != nullptr)
        {
            x = x->left;
        }
        return x;
    }

    // Максимальный элемент
    Node* maximum(Node* x)
    {
        if (len == 0)
            return nullptr;

        while (x->right != nullptr)
        {
            x = x->right;
        }
        return x;
    }

    Node* next(Node* x)
    {
        if (x->right != nullptr)
            return minimum(x->right);

        Node* parent = x->parent;
        while (parent != nullptr && x == parent->right)
        {
            x = parent;
            parent = parent->parent;
        }
        return parent;
    }

    // Удаление элемента
    void remove(Node* n)
    {
        // если элемент не найден
        if (n == nullptr)
            return;

        // чайлдфри
        if (n->left == nullptr && n->right == nullptr)
        {
            if (n->parent->left = n)
                n->parent->left = nullptr;
            else
                n->parent->right = nullptr;
            delete n;
            return;
            //n = nullptr;
        }

        // один ребенок
        if (n->left == nullptr || n->right == nullptr)
        {
            if (n->left != nullptr)
            {
                n->left->parent = n->parent;
                n->parent->left == n ? n->parent->left = n->left : n->parent->right = n->left;
            }
            else
            {
                n->right->parent = n->parent;
                n->parent->left == n ? n->parent->left = n->right : n->parent->right = n->right;
            }
            
            delete n;
            return;
        }

        // многодетная семья
        Node* y = next(n);
        n->key = y->key;
        remove(y);
    }
    
public:
    // Вставка элемента в дерево
    void insert(T x)
    {
        // создание головы (первого элемента)
        if (head == nullptr)
        {
            head = (Node*)malloc(sizeof(Node));
            head->parent = nullptr;
            head->left = nullptr;
            head->right = nullptr;
            head->key = x;
            len = 1;
            return;
        }
        
        Node* n = head; // добавляемый элемент
        Node* parent; // ссылка на родителя добавляемого элемента

        do
        {
            parent = n;
            if (x < n->key)
            {
                n = n->left;
            }
            else if (x > n->key)
            {
                n = n->right;
            }
            else
                return;
            
        }
        while (n != nullptr);

        n = (Node*)malloc(sizeof(Node)); // выделение памяти под новый элемент
        
        x < parent->key ? parent->left = n : parent->right = n; // ссылка на ребенка родителю

        // иницилизация элемента
        n->parent = parent;
        n->left = nullptr;
        n->right = nullptr;
        n->key = x;

        len++; // увеличение длины
    }

    // Удаление элемента
    void remove(T x)
    {
        // поиск удаляемого элемента
        Node* n = search(x);

        // если элемент не найден
        if (n == nullptr)
            return;

        remove(n);
    }

    // Минимальный элемент
    T min()
    {
        return minimum(head)->key;
    }

    // Максимальный элемент
    T max()
    {
        return maximum(head)->key;
    }

    T next(T x)
    {
        Node* n = search(x);

        if (n == nullptr)
            return NAN;
        
        return next(n)->key;
    }

    // Очистка памяти
    void clear()
    {
        Node* n = head;
        
        while (n != nullptr) {
            while (n->left != nullptr || n->right != nullptr)
            {
                if (n->left != nullptr)
                    n = n->left;
                else
                    n = n->right;
            }
            
            if (n->parent == nullptr)
            {
                delete head;
                head = nullptr;
                len = 0;
                return;
            }
            
            if (n->parent->left == n)
                n->parent->left = nullptr;
            else
                n->parent->right = nullptr;
            
            delete n;
            n = head;
        }
    }
};
