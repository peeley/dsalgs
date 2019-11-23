// Singly linked list
#include <iostream>
using std::cout;
using std::endl;

template<typename T>
class LinkedList{
    public:
        LinkedList(const T& val): value(val), next(nullptr) {}
        ~LinkedList(){
            delete next;
        }
        T getValue(){
            return value;
        }
        T setValue(const T& val){
            value = val;
        }
        LinkedList<T>* getNext(){
            return next;
        }
        void setNext(LinkedList<T>* node){
            next = node;
        }
        void insert(const T& val){
            auto n = this;
            while(n->getNext()){
                n = n->getNext();
            }
            n->setNext(new LinkedList(val));
        }
        void print(){
            auto current = this;
            while(current != nullptr){
                cout << current->getValue() << " ";
                current = current->getNext();
            }
            cout << endl;
        }
    private:
        T value;
        LinkedList<T>* next;
};

int main(){
    auto list = LinkedList<int>(5);
    list.insert(1);
    list.insert(2);
    list.insert(9);
    list.print();
}
