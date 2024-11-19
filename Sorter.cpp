#include "Sorter.h"

std::vector<int> Sorter::bubble_Sort(std::vector<int> list) {
    StartClock();
    int n = list.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (list[j] > list[j + 1]) {
                std::swap(list[j], list[j + 1]);
            }
        }
    }
    StopClock();
    return list;
}

std::vector<int> Sorter::selection_Sort(std::vector<int> list) {
    StartClock();
    for (int i = 0; i < list.size() - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < list.size(); j++) {
            if (list[min_idx] > list[j]) {
                min_idx = j;
            }
        }
        std::swap(list[i], list[min_idx]);
    }
    StopClock();
    return list;
}

std::vector<int> Sorter::insertion_Sort(std::vector<int> list) {
    StartClock();
    for (int i = 1; i < list.size(); i++) {
        int key = list[i];
        int j = i - 1;
        while (j >= 0 && key < list[j]) {
            list[j + 1] = list[j];
            j--;
        }
        list[j + 1] = key;
    }
    StopClock();
    return list;
}

void Sorter::PrintList(std::vector<int> list) {
    for (int x : list) {
        std::cout << x << " ";
    }
}

void Sorter::StartClock() {
    this->startTime = std::chrono::high_resolution_clock::now();
}

void Sorter::StopClock() {
    this->endTime = std::chrono::high_resolution_clock::now();
    this->duration = std::chrono::duration_cast<std::chrono::microseconds>(
        this->endTime - this->startTime);
}

void Sorter::PrintLastRuntime() {
    std::cout << "Last sort took " << this->duration.count() << " microseconds.\n\n";
}