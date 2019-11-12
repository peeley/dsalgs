#include<memory>
using std::shared_ptr;
using std::make_shared;

#include<iostream>
using std::cout;
using std::endl;

#include<string>
using std::string;

template<typename T>
class AVLTree {
    public:
        AVLTree(const T& v): value(v), parent(nullptr), left(nullptr), 
                             right(nullptr) {}
        ~AVLTree(){
            cout << "Destructing node w/ val" << value << endl;
            cout << "Deleting left: " << endl;
            delete left;
            cout << "Deleting right: " << endl;
            delete right;
        }
        T getValue() const{
            return value;
        }
        void insert(const T& val){
            if(val < value){
                if(left == nullptr){
                    auto newTree = new AVLTree<T>(val);
                    newTree->parent = this;
                    left = newTree;
                }
                else{
                    left->insert(val);
                }
            }
            else {
                if(right == nullptr){
                    auto newTree = new AVLTree<T>(val);
                    newTree->parent = this;
                    right = newTree;
                }
                else{
                    right->insert(val);
                }
            }
        }
        int getHeight(){
            int height = 1;
            if(left != nullptr){
                height += left->getHeight();
            }
            if(right != nullptr){
                height += right->getHeight();
            }
            return height;
        }
        AVLTree* getParent(){
            return parent;
        }
        AVLTree* getLeft(){
            return left;
        }
        AVLTree* getRight(){
            return right;
        }
        AVLTree* rotateLeft(){
            AVLTree<T>* temp = right;
            right = temp->left;
            if(temp->left){
                temp->left->parent = this;
            }
            temp->parent = parent;
            if(parent){
                if(parent->left == this){
                    parent->left = temp;
                }
                else{
                    parent->right = temp;
                }
            }
            temp->left = this;
            parent = temp;
            return temp;
        }
        AVLTree* rotateRight(){
            AVLTree<T>* temp = left;
            left = temp->right;
            if(temp->right){
                temp->right->parent = this;
            }
            temp->parent = parent;
            if(parent){
                if(parent->left == this){
                    parent->left = temp;
                }
                else{
                    parent->right = temp;
                }
            }
            temp->right = this;
            parent = temp;
            return temp;
        }

    private:
        T value;
        AVLTree<T>* parent;
        AVLTree<T>* left;
        AVLTree<T>* right;
};

template<typename T>
void printTree(AVLTree<T>* tree, int depth){
    string padding;
    for(auto i=0; i<depth; i++){
        padding += " ";
    }
    if(!tree){
        cout << padding << "null" << endl;
        return;
    }
    cout << padding << tree->getValue();
    auto parent = tree->getParent();
    parent ? (cout << ", parent is " << parent->getValue() << endl) 
        : (cout << endl);
    padding += " ";
    printTree(tree->getLeft(), depth+2);
    printTree(tree->getRight(), depth+2);
}
