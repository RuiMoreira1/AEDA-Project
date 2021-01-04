#pragma once
#include <stack>

template<class T> class inOrderIterator;
template<class T> class preOrderIterator;
template<class T> class posOrderIterator;


/**
 * class Node
 * @param node - the element to be include inside de node
 * @param left - pointer to the left node
 * @param right - pointer to the right node
 */
template <class T>
class Node{
public:
    T node;
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
    Node<T> *find(Node<T> *node, T comparable);
    Node<T> *remove(Node<T> *node, T comparable);
    Node<T> *findMin(Node<T> *node);
    void clearTree(Node<T>* nodeToClear);
    friend class inOrderIterator<T>;
    friend class preOrderIterator<T>;
    friend class posOrderIterator<T>;
public:
    BST();
    BST(T root);
    ~BST();
    void insert(T &newElement);
    void remove(T &Element);
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

/**
 * class preOrderIterator - iterator to a binary tree in pre order
 * @param binaryTree - stack on witch the tree is stored
 */
template<class T>
class preOrderIterator{
    std::stack<T> binaryTree;
    void copyBST(Node<T> *node);
public:
    preOrderIterator(BST<T> &bst);
    void advance();
    T retrieve();
    T operator *();
    bool isAtEnd();
};

/**
 * class posOrderIterator - iterator to a binary tree in pos order
 * @param binaryTree - stack on witch the tree is stored
 */
template<class T>
class posOrderIterator{
    std::stack<T> binaryTree;
    void copyBST(Node<T> *node);
public:
    posOrderIterator(BST<T> &bst);
    void advance();
    T retrieve();
    T operator *();
    bool isAtEnd();
};

