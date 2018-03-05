#ifndef BST_HPP
#define BST_HPP

#include <iostream>

template <typename T>
struct Node {
    T value;
    Node<T>* left;
    Node<T>* right;
    int lsize;
    int size;

    Node(T value)
    {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
        this->lsize = 0;
        this->size = 1;
    }

    void print()
    {
        std::cout << this->value << " ";
    }
};

template <typename T>
class Bst {
private:
    Node<T>* root;

    Node<T>* insert(Node<T>*&, const T&);

    Node<T>* remove(Node<T>*&, const T&);

    void inorder(Node<T>*&) const;

    T select(Node<T>*&, const int);

    int rank(Node<T>*&, const T&) const;

    bool search(Node<T>*&, const T&);

    int depth(Node<T>*&);

    int rank(Node<T>*&, const T&);

public:
    Bst(const T&);
    Bst(const Bst&);
    Bst& operator=(const Bst&);
    ~Bst();

    Node<T>* min_node_in_subtree(Node<T>*&);
    Node<T>* get_root();

    void insert(const T&);
    void remove(const T&);

    // returns key with given rank
    int rank(const T&);

    // number of keys less than given key
    T select(int);

    bool search(const T&);
    int depth();

    void print() const;
};

#endif /* BST_HPP */
