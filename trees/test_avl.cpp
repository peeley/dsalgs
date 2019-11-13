#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#include "AVLTree.cpp"

int main(){
    AVLTree<int> tree(7);
    tree.insert(6);
    tree.insert(4);
    tree.insert(3);
    tree.insert(5);
    tree.insert(8);
    tree.print();
    cout << endl << endl;
}
