#ifndef utils_hpp
#define utils_hpp
#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

template<typename T>
void printVec(vector<T>& vec, int low, int high){
    for(int i = low; i < high; i++){
        auto num = vec[i];
        cout << num << " ";
    }
    cout << endl;
}

#endif
