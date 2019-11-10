#include "minHeap.cpp"

int main(){
    vector<char> v = {'a', 'b', 'c', 'd', 'e'};
    MinHeap<char> heap = MinHeap<char>::heapify(v);
    cout << heap << endl;
}
