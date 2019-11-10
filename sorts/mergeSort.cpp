// Noah Snelson
// Merge sort implementation

#ifndef mergesort_hpp
#define mergesort_hpp

#include <vector>
using std::vector;
#include<iostream>
using std::cout;
using std::endl;

#include "utils.cpp"

template<typename T> 
vector<T> merge(vector<T>& left, vector<T>& right){
    size_t leftIdx=0; size_t rightIdx=0;
    vector<T> newVec = {};
    while(leftIdx < left.size() && rightIdx < right.size()){
        auto leftVal = left[leftIdx];
        auto rightVal = right[rightIdx];
        if(leftVal < rightVal){
            newVec.push_back(leftVal);
            ++leftIdx;
        }
        else{
            newVec.push_back(rightVal);
            ++rightIdx;
        }
    }
    while(leftIdx < left.size()){
        newVec.push_back(left[leftIdx]);
        ++leftIdx;
    }
    while(rightIdx < right.size()){
        newVec.push_back(right[rightIdx]);
        ++rightIdx;
    }
    return newVec;
}

template<typename T>
vector<T> mergeSort(vector<T>& vec){
    if(vec.size() == 1){
        return vec;
    }
    size_t mid = vec.size()/2;
    vector<T> left = {};
    for(size_t i = 0; i < mid; i++){
        left.push_back(vec[i]);
    }
    vector<T> right = {};
    for(size_t i = mid; i < vec.size(); i++){
        right.push_back(vec[i]);
    }
    left = mergeSort(left);
    right = mergeSort(right);
    return merge(left, right);
}

#endif
