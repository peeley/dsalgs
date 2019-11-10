// Noah Snelson
// Implements quicksort algorithm
#ifndef quicksort_hpp
#define quicksort_hpp
#include<vector>
using std::vector;

#include "utils.cpp"

// Setting partition to median value is recommended for O(nlogn) performance.
enum class PartType {lowest, highest, median};

// Utilizes Lomuto partition scheme.
template<typename T>
void quicksortRecurse(vector<T>& vec, int lowIdx, int highIdx, PartType p){
    auto low = lowIdx;
    auto high = highIdx;
    T pivotVal;
    switch(p){
        case PartType::lowest: 
            pivotVal = vec[low]; break;
        case PartType::highest: 
            pivotVal = vec[high]; break;
        case PartType::median: 
            pivotVal = vec[(low+high)/2]; break;
    }                 
    while(lowIdx < highIdx){
        while(vec[lowIdx] < pivotVal){
            lowIdx += 1;
        }
        while(vec[highIdx] > pivotVal){
            highIdx -= 1;
        }
        if(lowIdx <= highIdx){
            std::swap(vec[lowIdx], vec[highIdx]);
            lowIdx += 1;
            highIdx -= 1;
        }
    }
    if(low < highIdx){
        quicksortRecurse(vec, low, highIdx, p);
    }
    if(lowIdx < high){
        quicksortRecurse(vec, lowIdx, high, p);
    }
}

template<typename T>
void quicksort(vector<T>& vec, PartType p){
    quicksortRecurse(vec, 0, vec.size()-1, p);
}

#endif
