#include <cstddef>
#include "BST.h"

///////Nodes methods

///Node empty constructor
template<class T>
Node<T>::Node() {
    T empty;
    node = empty;
    left = nullptr;
    right = nullptr;

}

///Create a Node with the element
template<class T>
Node<T>::Node(T element) {
    node = element;
    left = nullptr;
    right = nullptr;

}

///Recursivly insert a new element in a node
template<class T>
void Node<T>::insert(Node *element) {
    if(left == nullptr && element->getElement() < node) this->left = element;
    else if (right == nullptr && node < element->getElement()) this->right = element;
    else if (element->getElement() < node) left->insert(element);
    else right->insert(element);
}

///////Binary search tree methods

///Binary tree empty constructor
template<class T>
BST<T>::BST() {
    Node<T>* empty = Node<T>();
    root = empty;
}

///BST constructor with a root
template<class T>
BST<T>::BST(T root) {
    Node<T> *newNode = new Node<T>(root);
    this->root = newNode;
}

///Insert a new element to the BST and allocate a new node
template<class T>
void BST<T>::insert(T &newElement) {
    Node<T>* newNode = new Node<T>(newElement);
    Node<T> emptyNode;
    if(*root == emptyNode) root = newNode;
    root->insert(newNode);
}

///Recursive function that return the element based on the comparable or the empty Node
template<class T>
Node<T>* BST<T>::find(Node<T> *node, T comparable) {
    if(node == nullptr) return nullptr;
    else if(node->getElement() < comparable) return find(node->right, comparable);
    else if (comparable < node->getElement()) return find(node->left, comparable);
    else return node;
}

///BST find function with a comparable that returns the element or the empty Node
template<class T>
T BST<T>::find(T comparable) {
    Node<T>* nodePtr = find(root, comparable);
    T empty;
    if(nodePtr == nullptr) return empty;
    return nodePtr->node;
}

///Recursively deallocate the nodes
template<class T>
void BST<T>::clearTree(Node<T> *nodeToClear) {
    if(nodeToClear->left != nullptr) clearTree(nodeToClear->left);
    if(nodeToClear->right != nullptr) clearTree(nodeToClear->right);
    delete nodeToClear;
}

///Find the minimum value in a tree
template<class T>
Node<T> * BST<T>::findMin(Node<T> *node) {
    if(node->left == nullptr) return node;
    else return findMin(node->left);
}

///Remove a element in a tree
template<class T>
void BST<T>::remove(T &Element) {
    remove(root, Element);
}

///Remove a element in a tree with root node
template<class T>
Node<T> *BST<T>::remove(Node<T> *node, T comparable) {
    if(node == nullptr) return node;
    else if (node->getElement() < comparable) node->right = remove(node->right, comparable);
    else if (comparable < node->getElement()) node->left = remove(node->left, comparable);

    else{
        if(node->left == nullptr && node->right == nullptr){
            delete node;
            return nullptr;
        }
        else if (node->left == nullptr){
            Node<T>* tmp = node->right;
            delete node;
            return tmp;
        }
        else if (node->right == nullptr){
            Node<T> *tmp = node->left;
            delete node;
            return tmp;
        }
        else{
            node->node = findMin(node->right)->node;
            remove(node->right, node->node);
            return node;
        }
    }

}

///Deconstructor clears the tree deallocating the nodes
template<class T>
BST<T>::~BST<T>() {
    clearTree(root);
}

///////Iterator methods

///Iterator constructor using a BST
template<class T>
inOrderIterator<T>::inOrderIterator(BST<T> &bst) {
    if (bst.root != nullptr) copyBST(bst.root);
}

///Recursively travel through the BST in reverse so the stack stays in order
template<class T>
void inOrderIterator<T>::copyBST(Node<T> *node) {
    if(node->right != nullptr) {
        copyBST(node->right);
    }
    binaryTree.push(node->getElement());
    if(node->left != nullptr){
        copyBST(node->left);
    }
}

///Returns the element in the Nodes
template<class T>
T inOrderIterator<T>::operator*() {
    return binaryTree.top();
}

///Returns the element in the Nodes
template<class T>
T inOrderIterator<T>::retrieve() {
    return binaryTree.top();
}

///Goes to the next element by poping the stack
template<class T>
void inOrderIterator<T>::advance() {
    if(!binaryTree.empty()) binaryTree.pop();
}

///Return true if the stack is empty
template<class T>
bool inOrderIterator<T>::isAtEnd() {
    return binaryTree.empty();
}

///iterator constructor using a BST
template<class T>
preOrderIterator<T>::preOrderIterator(BST<T> &bst) {
    if(bst.root != nullptr) copyBST(bst.root);
}

///Recursively travel through the BST in reverse of the pre order so the stack stays in order
template<class T>
void preOrderIterator<T>::copyBST(Node<T> *node) {
    if(node->right != nullptr) copyBST(node->right);
    if(node->left != nullptr) copyBST(node->left);
    binaryTree.push(node->getElement());
}

///Advance iterator
template<class T>
void preOrderIterator<T>::advance() {
    binaryTree.pop();
}

///Return the Element inside the top of the stack
template<class T>
T preOrderIterator<T>::retrieve() {
    return binaryTree.top();
}

///Return the Element inside the top of the stack
template<class T>
T preOrderIterator<T>::operator*() {
    return binaryTree.top();
}

///Return true if the stack is empty
template<class T>
bool preOrderIterator<T>::isAtEnd() {
    return binaryTree.empty();
}

///iterator constructor using a BST
template<class T>
posOrderIterator<T>::posOrderIterator(BST<T> &bst) {
    if(bst.root != nullptr) copyBST(bst.root);
}

///Recursively travel through the BST in reverse of the pos order so the stack stays in order
template<class T>
void posOrderIterator<T>::copyBST(Node<T> *node) {
    binaryTree.push(node->getElement());
    if(node->right != nullptr) copyBST(node->right);
    if(node->left != nullptr) copyBST(node->left);
}

///Advance iterator
template<class T>
void posOrderIterator<T>::advance() {
    binaryTree.pop();
}

///Return the Element inside the top of the stack
template<class T>
T posOrderIterator<T>::retrieve() {
    return binaryTree.top();
}

///Return the Element inside the top of the stack
template<class T>
T posOrderIterator<T>::operator*() {
    return binaryTree.top();
}

///Return true if the stack is empty
template<class T>
bool posOrderIterator<T>::isAtEnd() {
    return binaryTree.empty();
}
