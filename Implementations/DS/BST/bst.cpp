#include "bst.hpp"
#include <algorithm>
#include <limits.h>

template <typename T>
Bst<T>::Bst(const T& value)
{
    this->root = new Node<T>(value);
}

template <typename T>
Bst<T>::Bst(const Bst& other)
{
    this->root = other.root;
}

template <typename T>
Bst<T>& Bst<T>::operator=(const Bst& other)
{
    if (this != &other) {
        delete this->root;
        this->root = other.root;
    }

    return *this;
}

template <typename T>
Bst<T>::~Bst()
{
    delete this->root;
}

template <typename T>
Node<T>* Bst<T>::get_root()
{
    return this->root;
}

template <typename T>
void Bst<T>::inorder(Node<T>*& root) const
{
    if (!root) {
        return;
    }

    if (root->left) {
        inorder(root->left);
    }

    root->print();

    if (root->right) {
        inorder(root->right);
    }
}

template <typename T>
void Bst<T>::print() const
{
    Node<T>* r = this->root;
    inorder(r);
    std::cout << std::endl;
}

template <typename T>
Node<T>* Bst<T>::insert(Node<T>*& root, const T& value)
{
    if (!root) {
        root = new Node<T>(value);
        root->size++;
        return root;
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
        root->lsize++;
    } else {
        root->right = insert(root->right, value);
    }

    root->size++;

    return root;
}

template <typename T>
void Bst<T>::insert(const T& value)
{
    root = insert(this->root, value);
}

template <typename T>
Node<T>* Bst<T>::min_node_in_subtree(Node<T>*& root)
{
    if (!root->left) {
        return root;
    }

    root = min_node_in_subtree(root->left);
    return root;
}

template <typename T>
Node<T>* Bst<T>::remove(Node<T>*& root, const T& value)
{
    if (!root) {
        return nullptr;
    }
    // no children
    if (root->value == value) {
        if (!root->left && !root->right) {
            root->size--;
            root = nullptr;
            return root;
        }

        // one child - left
        if (root->left && !root->right) {
            root->lsize--;
            root->size--;
            root = root->left;
            root->left = nullptr;
            return root;
        }

        // one child - right
        if (root->right && !root->left) {
            root = root->right;
            root->right = nullptr;
            root->size--;
            return root;
        }

        // two children
        if (root->right && root->left) {
            Node<T>* min = min_node_in_subtree(root->right);
            root->value = min->value;
            root->right = remove(root->right, min->value);
            root->size--;
            return root;
        }
    } else if (value < root->value) {
        root->left = remove(root->left, value);
        if (root) {
            root->lsize--;
        }
    } else {
        root->right = remove(root->right, value);
    }

    if (root) {
        root->size--;
    }

    return root;
}

template <typename T>
void Bst<T>::remove(const T& value)
{
    this->root = remove(this->root, value);
}

template <typename T>
bool Bst<T>::search(Node<T>*& root, const T& value)
{
    if (value == root->value) {
        return true;
    }

    if (value < root->value) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

template <typename T>
bool Bst<T>::search(const T& value)
{
    return search(this->root, value);
}

template <typename T>
int Bst<T>::depth(Node<T>*& root)
{
    if (!root) {
        return 0;
    }

    return 1 + std::max(depth(root->left), depth(root->right));
}

template <typename T>
int Bst<T>::depth()
{
    return depth(this->root);
}

template <typename T>
T Bst<T>::select(Node<T>*& root, const int key)
{
    if (!root) {
        return (int)NULL;
    }
    int root_rank = root->lsize;

    if (root_rank == key) {
        return root->value;
    } else if (root_rank < key) {
        return select(root->right, key - root_rank - 1);
    } else {
        return select(root->left, key);
    }
}

template <typename T>
T Bst<T>::select(const int key)
{
    return select(this->root, key);
}

template <typename T>
int Bst<T>::rank(Node<T>*& root, const T& value)
{
    if (!search(value) || !root) {
        return (int)NULL;
    }

    int root_rank = root->lsize;

    if(value == root->value) {
        return root_rank;
    } else if (value < root->value){
        return rank(root->left, value);
    } else {
        return 1 + root_rank + rank(root->right, value);
    }
}

template <typename T>
int Bst<T>::rank(const T& value)
{
    return rank(this->root, value);
}
