#include <iostream>
#include <string>
#include "BST.cpp"

using namespace std;

class Test{
public:
    string name;
    int ID;
    Test() { name = "notFound"; ID = -1;}
    bool operator < (Test rhs) { return ID < rhs.ID;}
    bool operator == (Test &rhs){ return ID == rhs.ID;}
};

int main() {
    Test P1;
    P1.ID = 3;
    P1.name = "asdf";
    Test P2;
    P2.ID = 1;
    P2.name  = "asdf";
    Test P3;
    P3.ID = 2;
    P3.name = "teste2";
    Test P4;
    P4.name = "teste";
    P4.ID = 23;

    BST<Test> binaryTree(P1);
    binaryTree.insert(P2);
    binaryTree.insert(P3);
    binaryTree.insert(P4);

    Test find;
    find.ID = 5;
    cout << binaryTree.find(find).name << endl;
    return 0;
}
