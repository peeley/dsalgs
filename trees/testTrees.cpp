
#include "binTree.cpp"

int main(){
    BinTree<int> tree;
    for(int i = 0; i < 20; i++){
        tree.insert(rand()%100);
    }
    printTree(tree, 0);
    tree.traverse();
}
