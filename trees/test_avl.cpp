#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#include "AVLTree.cpp"

const int TREE_SIZE = 60;

int main(){
    srand(time(NULL));
    /*
    AVLTree<int> tree(rand() % 100);
    for(int i=0; i < TREE_SIZE; i++){
        tree.insert(rand() % 100);
    }
    */
    AVLTree<int> tree(3);
    tree.insert(0);
    tree.insert(5);
    tree.insert(1);
    tree.print();
    tree.remove(0);
    tree.print();
    cout << "Tree height: " << tree.getHeight() << endl;
    cout << "Tree balance: " << tree.getBalance() << endl;
}
