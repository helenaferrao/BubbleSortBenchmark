#ifndef SORT_H
#define SORT_H

#include <vector>
#include <algorithm>


template <typename T, typename Compare>
void bubbleSort(std::vector<T>& arr, Compare comp) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) { 
            if (comp(arr[j + 1], arr[j])) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}


template <typename T, typename Compare>
void bubbleSortReduced(std::vector<T>& arr, Compare comp) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {  
            if (comp(arr[j + 1], arr[j])) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}


template <typename T, typename Compare>
void bubbleSortWithFlag(std::vector<T>& arr, Compare comp) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {  
            if (comp(arr[j + 1], arr[j])) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {  
            break;
        }
    }
}

#endif 

