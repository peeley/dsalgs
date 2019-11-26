#include<iostream>
using std::cout;
using std::endl;

const size_t DEFAULT_CAP=5;

template<typename T>
class Queue{
    public:
        Queue(){
            data = new T[DEFAULT_CAP];
        }
        ~Queue(){
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

int main(){
    Queue<int> q;
    for(int i = 0; i < DEFAULT_CAP*4; i++){
        q.push(i);
    }
    q.print();
    q.pop();
    q.print();
}
