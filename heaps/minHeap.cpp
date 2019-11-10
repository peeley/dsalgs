// Noah Snelson
// Implements minheap as defined in https://en.wikipedia.org/wiki/Binary_heap
#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::to_string;
using std::cout;
using std::endl;

template<typename T>
class MinHeap{
    friend std::ostream& operator<<(std::ostream& os, MinHeap& h){
        os << h.recursePrint(0, 0);
        return os;
    }
    public:
        MinHeap(){
            _data = {};
        }
        MinHeap(T val){
            _data = {val};
        }
        void insert(T val){
            _data.push_back(val);
            size_t valIdx = _data.size()-1;
            size_t parentIdx = _data.size()/2;
            while(_data[valIdx] < _data[parentIdx]){
                auto temp = _data[parentIdx];
                _data[parentIdx] = val;
                _data[valIdx] = temp;
                valIdx = parentIdx;
                if(valIdx == 0){
                    break;
                }
                parentIdx = parentIdx/2;
            }
        }
        T pop(){
            T returnVal = _data[0];
            _data[0] = _data[_data.size()-1];
            _data.pop_back();
            size_t swapIdx = 0;
            size_t leftChildIdx;
            size_t rightChildIdx;
            while(swapIdx < _data.size()-1){
                leftChildIdx = (2 * swapIdx) + 1;
                rightChildIdx = (2 * swapIdx) + 2;
                if(_data[swapIdx] > _data[leftChildIdx]){ // smaller than left child
                    if(_data[rightChildIdx] && 
                        _data[leftChildIdx] < _data[rightChildIdx]){
                        std::swap(_data[swapIdx], _data[swapIdx+1]);
                        swapIdx = leftChildIdx;
                    }
                }
                else if(_data[swapIdx] > _data[rightChildIdx]){ // smaller than right child
                    if(_data[rightChildIdx] < _data[leftChildIdx]){
                        std::swap(_data[swapIdx], _data[swapIdx+2]);  
                        swapIdx = rightChildIdx;
                    }
                }
                else{
                    break;
                }
            }
            return returnVal;
            
        }
        T top() const{
            return _data[0];
        }
        static MinHeap heapify(const vector<T>& v){
            MinHeap m;
            for(const auto& num : v){
                m.insert(num);
            }
            return m;
        }
    private:
        string recursePrint(int tabs, size_t idx){
            string tabStr = "";
            for(int i = 0; i < tabs; i++){
                tabStr += "  ";
            }
            string str = "";
            str += to_string(_data[idx]);
            tabStr += "  ";
            if(_data.size() > (2*idx+1)){
                str += "\n" + tabStr + "Left: " + recursePrint(tabs+1, 2*idx+1);
            }
            if(_data.size() > (2*idx+2)){
                str += "\n" + tabStr + "Right: " + recursePrint(tabs+1, 2*idx+2);
            }
            return str;
        }
        vector<T> _data;
};
