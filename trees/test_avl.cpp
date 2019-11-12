#include<iostream>
using std::cout;
using std::endl;

#include "AVLTree.cpp"

int main(){
    AVLTree<int> tree(5);
    tree.insert(6);
    tree.insert(4);
    tree.insert(3);
    tree.insert(7);
    tree.insert(8);
    printTree(&tree, 0);
    cout << endl << endl;
    tree = *(tree.rotateLeft());
    //printTree(&tree, 0);
}
