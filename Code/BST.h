#pragma once
#include <stack>

template<class T> class inOrderIterator;

/**
 * class Node
 * @param node - the element to be include inside de node
 * @param left - pointer to the left node
 * @param right - pointer to the right node
 */
template <class T>
class Node{
    T node;
public:
    Node* left;
    Node* right;
    Node();
    Node(T element);
    T getElement() {return node;}
    void insert(Node* element);
    bool operator < (Node<T> &rhs) { return node < rhs.node;}
    bool operator == (Node<T> rhs) {return !(node < rhs.node) && !(rhs.node < node);}
};

/**
 * class BST - binary search tree
 * @param root - the pointer to de first root of the tree
 */
template <class T>
class BST {
private:
    Node<T> *root;
    T find(Node<T> *node, T comparable);
    friend class inOrderIterator<T>;
public:
    BST();
    BST(T root);
    ~BST();
    void clearTree(Node<T>* nodeToClear);
    void insert(T &newElement);
    T find(T comparable);
};

/**
 * class inOrderIterator - iterator to a binary tree in order
 * @param binaryTree - stack on witch the tree is stored
 */
template<class T>
class inOrderIterator{
    std::stack<T> binaryTree;
    void copyBST(Node<T> *node);
public:
    inOrderIterator(BST<T> &bst);
    void advance();
    T retrieve();
    T operator *();
    bool isAtEnd();
};