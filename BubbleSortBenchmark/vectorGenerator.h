#ifndef VECTOR_GENERATE_H
#define VECTOR_GENERATE_H

#include <vector>
#include <cstdlib>
#include <ctime>


template <typename T>
std::vector<T> generateRandomVector(size_t n) {
    std::vector<T> result;
    result.reserve(n); 

    static bool seeded = false;
    if (!seeded) {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        seeded = true;
    }

    for (size_t i = 0; i < n; ++i) {
        result.push_back(static_cast<T>(std::rand())); 
    }

    return result;
}


template <typename T>
std::vector<T> generateSortedVector(size_t n) {
    std::vector<T> result;
    result.reserve(n);

    for (size_t i = 0; i < n; ++i) {
        result.push_back(static_cast<T>(i + 1)); /
    }

    return result;
}

template <typename T>
std::vector<T> generateSortedReverseVector(size_t n) {
    std::vector<T> result;
    result.reserve(n);

    for (size_t i = 0; i < n; ++i) {
        result.push_back(static_cast<T>(n - i)); 
    }

    return result;
}

#endif 

