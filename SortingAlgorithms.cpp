#include "SortingAlgorithms.h"
#include <thread>
#include <chrono>

void delay(std::function<void()> onStep) {
    onStep();
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
}

void SortingAlgorithms::bubbleSort(std::vector<int>& arr, std::function<void()> onStep) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        for (size_t j = 0; j < arr.size() - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                delay(onStep);
            }
        }
    }
}

void SortingAlgorithms::selectionSort(std::vector<int>& arr, std::function<void()> onStep) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            std::swap(arr[i], arr[minIndex]);
            delay(onStep);
        }
    }
}

void quickSortHelper(std::vector<int>& arr, int low, int high, std::function<void()> onStep) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; ++j) {
            if (arr[j] < pivot) {
                i++;
                std::swap(arr[i], arr[j]);
                delay(onStep);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        delay(onStep);

        int pivotIndex = i + 1;

        quickSortHelper(arr, low, pivotIndex - 1, onStep);
        quickSortHelper(arr, pivotIndex + 1, high, onStep);
    }
}

void SortingAlgorithms::quickSort(std::vector<int>& arr, std::function<void()> onStep) {
    quickSortHelper(arr, 0, arr.size() - 1, onStep);
}
