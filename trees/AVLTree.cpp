#include<memory>
using std::shared_ptr;
using std::make_shared;

#include<iostream>
using std::cout;
using std::endl;

template<typename T>
class AVLTree {
    public:
        AVLTree(T v): value(v), parent(nullptr), left(nullptr), right(nullptr){}
        T getValue() const{
            return value;
        }
        T insert(T val){
            auto newTree = make_shared<AVLTree<T>>(val);
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
            cout << "here";
            auto tempP = parent;
            parent = parent ? parent->getParent() : nullptr;
            parent->right = left;
            left = tempP;
        }
        void rotateRight(){
            auto tempP = parent;
            parent = parent->getParent();
            parent->left = right;
            right = tempP;
        }

    private:
        T value;
        shared_ptr<AVLTree> parent;
        shared_ptr<AVLTree> left;
        shared_ptr<AVLTree> right;
};
