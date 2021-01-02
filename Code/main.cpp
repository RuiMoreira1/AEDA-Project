#include <iostream>
#include <string>
#include "BST.cpp"
#include "ProgramLoop.h"

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
    P1.name = "3";
    Test P2;
    P2.ID = 1;
    P2.name  = "1";
    Test P3;
    P3.ID = 2;
    P3.name = "2";
    Test P4;
    P4.name = "23";
    P4.ID = 23;

    BST<Test> binaryTree(P1);
    binaryTree.insert(P2);
    binaryTree.insert(P3);
    binaryTree.insert(P4);

    inOrderIterator<Test> it(binaryTree);

    while(!it.isAtEnd()){
        cout << it.retrieve().name << endl;
        it.advance();
    }
    Test find;
    find.ID = 23;
    cout << "ID = 23 name = " << binaryTree.find(find).name << endl;
    ProgramLoop d1;
    d1.ProgramLoop2();
    return 0;
}