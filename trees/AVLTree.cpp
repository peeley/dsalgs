#include<memory>
using std::shared_ptr;
using std::make_shared;

#include<iostream>
using std::cout;
using std::endl;

#include<string>
using std::string;


template<typename T>
class AVLNode {
    public:
        AVLNode(const T& v): value(v), parent(nullptr), left(nullptr), 
                             right(nullptr) {}
        ~AVLNode(){
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
                    auto newTree = new AVLNode<T>(val);
                    newTree->parent = this;
                    left = newTree;
                }
                else{
                    left->insert(val);
                }
            }
            else {
                if(right == nullptr){
                    auto newTree = new AVLNode<T>(val);
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
        AVLNode* getParent(){
            return parent;
        }
        AVLNode* getLeft(){
            return left;
        }
        AVLNode* getRight(){
            return right;
        }
        AVLNode* rotateLeft(){
            AVLNode<T>* temp = right;
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
        AVLNode* rotateRight(){
            AVLNode<T>* temp = left;
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
        AVLNode<T>* parent;
        AVLNode<T>* left;
        AVLNode<T>* right;
};

template<typename T>
class AVLTree{
    public:
        AVLTree(const T& val){
            root = new AVLNode<T>(val);
        }
        ~AVLTree(){
            delete root;
        }
        void insert(const T& val){
            root->insert(val);
        }
        void print(){
            printTreeRecurse(root, 0);
        }
    private:
        void printTreeRecurse(AVLNode<T>* tree, int depth){
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
            printTreeRecurse(tree->getLeft(), depth+2);
            printTreeRecurse(tree->getRight(), depth+2);
        }
        AVLNode<T>* root;
};

