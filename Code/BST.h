#pragma once

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
    bool operator == (Node<T> rhs) {return node == rhs.node;}
};

template <class T>
class BST {
    Node<T> *root;
    T find(Node<T> *node, T comparable);
public:
    BST();
    BST(T root);
    ~BST();
    void clearTree(Node<T>* nodeToClear);
    void insert(T &newElement);
    T find(T comparable);
};


