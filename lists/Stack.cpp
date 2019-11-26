
#include<iostream>
using std::cout;
using std::endl;
#include<string>
using std::string;

const size_t DEFAULT_CAP=5;

template<typename T>
class Stack{
    public:
        Stack(){
            data = new T[DEFAULT_CAP];
        }
        ~Stack(){
            delete[] data;
        }
        void push(const T& val){ //push onto stack
            if(length == cap){
                cap = cap*2;
                T* newData = new T[cap];
                for(size_t i=0; i<length; i++){
                    newData[i] = data[i];
                }
                delete[] data;
                data = newData;
            }
            data[length] = val;
            length += 1;
        }
        T top() const{
            return data[length];
        }
        void pop(){
            auto ret = data[length];
            length -= 1;
        }
        void print(){
            for(size_t i=0; i<length; i++){
                cout << data[i] << " ";
            }
            cout << endl;
        }

    private:
        T* data;
        size_t cap=DEFAULT_CAP;
        size_t length = 0;
};

int main(){
    Stack<int> s;
    for(int i = 0; i < DEFAULT_CAP*4; i++){
        s.push(i);
    }
    s.print();
    s.pop();
    s.print();
}
