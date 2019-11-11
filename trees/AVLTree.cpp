#include<memory>
using std::shared_ptr;
using std::make_shared;

#include<iostream>
using std::cout;
using std::endl;

template<typename T>
class AVLTree {
    public:
        AVLTree(const T& v): value(v), parent(nullptr), left(nullptr), 
                             right(nullptr) {}
        T getValue() const{
            return value;
        }
        T insert(const T& val){
            auto newTree = make_shared<AVLTree<T>>(val);
            newTree->parent = shared_ptr<AVLTree<T>>(this);
            if(val < value){
                left = newTree;
            }
            else {
                right = newTree;
            }
            return val;
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
        shared_ptr<AVLTree<T>> getParent(){
            return parent;
        }
        shared_ptr<AVLTree<T>> getLeft(){
            return left;
        }
        shared_ptr<AVLTree<T>> getRight(){
            return right;
        }
        void rotateLeft(){
            cout << "here" << endl;
            shared_ptr<AVLTree<T>> tempP = parent;
            parent = tempP->getParent();
            cout << "here" << endl;
            if(parent != nullptr){
                parent->right = shared_ptr<AVLTree<T>>(this);
            }
            tempP->right = left;
            cout << "here" << endl;
            left = tempP;
            left->parent = shared_ptr<AVLTree<T>>(this);
            cout << "here" << endl;
        }
        void rotateRight(){
            auto tempP = parent;
            parent = parent->getParent();
            parent->left = right;
            right = tempP;
        }

    private:
        T value;
        shared_ptr<AVLTree<T>> parent;
        shared_ptr<AVLTree<T>> left;
        shared_ptr<AVLTree<T>> right;
};
