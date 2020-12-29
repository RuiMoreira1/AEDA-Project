//
// Created by ruipe on 23/12/2020.
//

#include <cstddef>
#include "BST.h"

template<class T>
Node<T>::Node() {
    T empty;
    node = empty;
    left = nullptr;
    right = nullptr;

}

template<class T>
Node<T>::Node(T element) {
    node = element;
    left = nullptr;
    right = nullptr;

}

template<class T>
void Node<T>::insert(Node *element) {
    if(left == nullptr && element->getElement() < node) this->left = element;
    else if (right == nullptr && node < element->getElement()) this->right = element;
    else if (element->getElement() < node) left->insert(element);
    else right->insert(element);
}

template<class T>
BST<T>::BST() {
    Node<T>* empty = Node<T>();
    root = empty;
}

template<class T>
BST<T>::BST(T root) {
    Node<T> *newNode = new Node<T>(root);
    this->root = newNode;
}

template<class T>
void BST<T>::insert(T &newElement) {
    Node<T>* newNode = new Node<T>(newElement);
    Node<T> emptyNode;
    if(*root == emptyNode) root = newNode;
    root->insert(newNode);
}

template<class T>
T BST<T>::find(Node<T> *node, T comparable) {
    T empty;
    if(node == nullptr) return empty;
    else if(node->getElement() < comparable) return find(node->right, comparable);
    else if (comparable < node->getElement()) return find(node->left, comparable);
    else return node->getElement();
}

template<class T>
T BST<T>::find(T comparable) {
    return find(root, comparable);
}

template<class T>
void BST<T>::clearTree(Node<T> *nodeToClear) {
    if(nodeToClear->left != nullptr) clearTree(nodeToClear->left);
    if(nodeToClear->right != nullptr) clearTree(nodeToClear->right);
    delete nodeToClear;
}

template<class T>
BST<T>::~BST<T>() {
    clearTree(root);
}