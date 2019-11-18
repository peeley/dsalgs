#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#include "AVLTree.cpp"

const int TREE_SIZE = 15;

int main(){
    srand(time(NULL));
    AVLTree<int> tree(rand() % 100);
    for(int i=0; i < TREE_SIZE; i++){
        tree.insert(rand() % 100);
    }
    tree.print();
    cout << "Tree height: " << tree.getHeight() << endl;
    cout << "Tree balance: " << tree.getBalance() << endl;
}
