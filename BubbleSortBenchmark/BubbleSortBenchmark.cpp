#include <iostream>
#include <vector>
#include <chrono>
#include "Sort.h"
#include "vectorGenerator.h"


template <typename T, typename Compare>
void testSort(const std::string& sortName,
    void (*sortFunction)(std::vector<T>&, Compare),
    std::vector<T> inputVec, Compare comp) {
    auto start = std::chrono::high_resolution_clock::now();
    sortFunction(inputVec, comp);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;
    std::cout << sortName << " took " << elapsed.count() << " seconds.\n";
}

int main() {
    using T = int; 

    std::vector<size_t> sizes = { 5000, 10000, 20000, 30000, 40000, 50000, 60000 };

    for (size_t n : sizes) {
        std::cout << "Testing with " << n << " elements:\n";

        auto randomVec = generateRandomVector<T>(n);
        std::cout << "Random elements:\n";
        testSort("Bubble Sort (Classic)", bubbleSort<T, std::less<T>>, randomVec, std::less<T>());
        testSort("Bubble Sort (Reduced)", bubbleSortReduced<T, std::less<T>>, randomVec, std::less<T>());
        testSort("Bubble Sort (With Flag)", bubbleSortWithFlag<T, std::less<T>>, randomVec, std::less<T>());

        
        auto sortedVec = generateSortedVector<T>(n);
        std::cout << "Sorted elements:\n";
        testSort("Bubble Sort (Classic)", bubbleSort<T, std::less<T>>, sortedVec, std::less<T>());
        testSort("Bubble Sort (Reduced)", bubbleSortReduced<T, std::less<T>>, sortedVec, std::less<T>());
        testSort("Bubble Sort (With Flag)", bubbleSortWithFlag<T, std::less<T>>, sortedVec, std::less<T>());

        auto reverseSortedVec = generateSortedReverseVector<T>(n);
        std::cout << "Reverse sorted elements:\n";
        testSort("Bubble Sort (Classic)", bubbleSort<T, std::less<T>>, reverseSortedVec, std::less<T>());
        testSort("Bubble Sort (Reduced)", bubbleSortReduced<T, std::less<T>>, reverseSortedVec, std::less<T>());
        testSort("Bubble Sort (With Flag)", bubbleSortWithFlag<T, std::less<T>>, reverseSortedVec, std::less<T>());

        std::cout << "----------------------------------------\n";
    }

    return 0;
}
