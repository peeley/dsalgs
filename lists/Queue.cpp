#include<iostream>
using std::cout;
using std::endl;

const size_t DEFAULT_CAP=5;

template<typename T>
class ArrayQueue{
    public:
        ArrayQueue(){
            data = new T[DEFAULT_CAP];
        }
        ~ArrayQueue(){
            delete[] data;
        }
        void push(const T& val){
            if(tail == cap){
                cap = cap*2;
                auto newData = new T[cap];
                for(size_t i=0; i<(tail-head); i++){
                    newData[i] = data[i+head];
                }
                delete[] data;
                data = newData;
            }
            data[tail] = val;
            tail += 1;
        }
        void pop(){
            head += 1;
        }
        T front(){
            return data[head];
        }
        void print(){
            for(size_t i=head; i<tail; i++){
                cout << data[i] << " ";
            }
            cout << endl;
        }
    private:
        T* data;
        size_t head=0;
        size_t tail=0;
        size_t cap = DEFAULT_CAP;
};

template<typename T>
class Node{
    public:
        Node(const T& val): data(val) {}
        ~Node(){
            delete next;
        }
        Node* getNext(){
            return next;
        }
        void setNext(Node<T>* n){
            next = n;
        }
        T getValue(){
            return data;
        }
    private:
        T data;
        Node<T>* next = nullptr;
};

template<typename T>
class ListQueue{
    public:
        ListQueue() = default;
        ~ListQueue(){
            delete head;
        }
        void push(const T& val){
            auto newNode = new Node<T>(val);
            if(!head){
                head = newNode;
            }
            else if(!tail){
                tail = newNode;
                head->setNext(tail);
            }
            else{
                tail->setNext(newNode);
                tail = tail->getNext();
            }
        }
        T front(){
            return head->getValue();
        }
        void pop(){
            auto newHead = head->getNext();
            head->setNext(nullptr);
            delete head;
            head = newHead;
        }
        void print(){
            auto current = head;
            while(current != nullptr){
                cout << current->getValue() << " ";
                current = current->getNext();
            }
            cout << endl;
        }
    private:
        Node<T>* head = nullptr;
        Node<T>* tail = nullptr;
};


int main(){
    ListQueue<int> q;
    for(int i = 0; i < DEFAULT_CAP*4; i++){
        q.push(i);
    }
    q.print();
    q.pop();
    q.print();
}
