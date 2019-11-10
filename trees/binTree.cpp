// Noah Snelson
// Implementation of binary tree

#ifndef binary_hpp_
#define binary_hpp_

#include <memory>
using std::shared_ptr;
using std::make_shared;

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

template<typename T>
class BinTree{
    public:
        BinTree(const T& val): _val(val), _left(nullptr), _right(nullptr){}
        BinTree(): _val(NULL), _left(nullptr), _right(nullptr){}
        ~BinTree() = default;
        T getVal() const{
            return _val;
        }
        shared_ptr<BinTree<T>> getLeft() const{
            return _left;
        }
        shared_ptr<BinTree<T>> getRight() const{
            return _right;
        }
        // inserts value into tree, O(logn) time
        void insert(const T& val){
            if(val < _val){
                if(_left){
                    _left->insert(val);
                }
                else{
                    _left = make_shared<BinTree<T>>(val);
                }
            }
            else{
                if(_right){
                    _right->insert(val);
                }
                else{
                    _right = make_shared<BinTree<T>>(val);
                }
            }
        }
        // prints in-order traversal
        void traverse(){
            if(_left)
                _left->traverse();
            cout << _val << " ";
            if(_right)
                _right->traverse();
        }
    private:
        T _val;
        shared_ptr<BinTree<T>> _left;
        shared_ptr<BinTree<T>> _right;
};

template<typename T>
void printTree(BinTree<T>& b, int level){
    string tabStr;
    for(int i=0; i<level; i++){
        tabStr += "  ";
    }
    cout << tabStr << b.getVal() << endl;
    tabStr += "  ";
    level += 1;
    if(b.getLeft())
        printTree(*(b.getLeft()), level);
    else
        cout << tabStr << "null" << endl;
    if(b.getRight())
        printTree(*(b.getRight()), level);
    else
        cout << tabStr << "null" << endl;
}
#endif
