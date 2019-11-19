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
        AVLNode(const T& v, AVLNode* p=nullptr): value(v), parent(p), 
            left(nullptr), right(nullptr) {}
        ~AVLNode(){
            delete left;
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
            int lHeight = left ? left->getHeight() : 0;
            int rHeight = right ? right->getHeight() : 0;
            return height + std::max(lHeight, rHeight);
        }
        int getBalance(){
            auto leftHeight = left ? left->getHeight() : 0;
            auto rightHeight = right ? right->getHeight() : 0;
            return leftHeight - rightHeight;
        }
        AVLNode* getParent(){
            return parent;
        }
        AVLNode* getLeft(){
            return left;
        }
        void setLeft(AVLNode* l){
            left = l;
        }
        AVLNode* getRight(){
            return right;
        }
        void setRight(AVLNode* r){
            right = r;
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
            root = new AVLNode<T>(val, nullptr);
        }
        ~AVLTree(){
            delete root;
        }
        void print(){
            printTreeRecurse(root, 0);
        }
        void insert(const T& val){
            root = insert_recurse(root, nullptr, val);
        }
        int getHeight(){
            return root->getHeight() - 1;
        }
        int getBalance(){
            return root->getBalance();
        }
    private:
        AVLNode<T>* insert_recurse(AVLNode<T>* node, AVLNode<T>* lastNode, 
                                    const T& val){
            if(node == nullptr){
                return new AVLNode<T>(val, lastNode);
            }
            else if(val < node->getValue()){
                node->setLeft(insert_recurse(node->getLeft(), node, val));
            }
            else if(val > node->getValue()){
                node->setRight(insert_recurse(node->getRight(), node, val));
            }
            int heightDiff = node->getBalance();
            if(heightDiff > 1 && val < node->getLeft()->getValue()){ // left rotate
                return node->rotateRight();
            }
            else if(heightDiff < -1 && val > node->getRight()->getValue()){ // right rotate
                return node->rotateLeft();
            }
            else if(heightDiff > 1 && val > node->getLeft()->getValue()){ // left right rotate
                node->setLeft(node->getLeft()->rotateLeft());
                return node->rotateRight();
            }
            else if(heightDiff < -1 && val < node->getRight()->getValue()){
                node->setRight(node->getRight()->rotateRight());
                return node->rotateLeft();
            }
            return node;
        }
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

