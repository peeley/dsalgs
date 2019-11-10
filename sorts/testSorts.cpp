#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

#include "quickSort.cpp"
#include "mergeSort.cpp"
#include "utils.cpp"

int main(){
    srand(time(NULL));
    vector<int> v;
    for(int i = 0; i < 30; i++){
         v.push_back(rand()%100);
    }
    //auto sorted = mergeSort(v);
    cout << "Unsorted: ";
    printVec(v, 0, v.size());
    quicksort(v, PartType::median);
    cout << "Sorted: ";
    printVec(v, 0, v.size());
}
