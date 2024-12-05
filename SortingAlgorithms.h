#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <vector>
#include <functional>

class SortingAlgorithms {
public:
    static void bubbleSort(std::vector<int>& arr, std::function<void()> onStep);
    static void selectionSort(std::vector<int>& arr, std::function<void()> onStep);
    static void quickSort(std::vector<int>& arr, std::function<void()> onStep);
};

#endif
