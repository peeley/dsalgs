#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#include "AVLTree.cpp"

const int TREE_SIZE = 60;

int main(){
    srand(time(NULL));
    AVLTree<int> tree(rand() % 100);
    int lastVal;
    for(int i=0; i < TREE_SIZE; i++){
        lastVal = rand() % 100;
        tree.insert(lastVal);
    }
    tree.print();
    tree.remove(lastVal);
    tree.print();
    cout << "Tree height: " << tree.getHeight() << endl;
    cout << "Tree balance: " << tree.getBalance() << endl;
}
