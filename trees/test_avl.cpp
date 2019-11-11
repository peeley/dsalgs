#include<iostream>
using std::cout;
using std::endl;

#include "AVLTree.cpp"

int main(){
    AVLTree<int> tree(5);
    cout << tree.getValue() << endl;
    cout << tree.getHeight() << endl;
    tree.insert(6);
    cout << tree.getHeight() << endl;
    cout << tree.getRight()->getValue() << endl;
    tree.getRight()->rotateLeft();
    cout << tree.getHeight() << endl;
}
