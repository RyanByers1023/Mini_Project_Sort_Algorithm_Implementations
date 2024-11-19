#pragma once
#include <vector>
#include <iostream> //for PrintList()
#include <chrono> //to keep track of how long each algo runs for

class Sorter {
public:
    std::vector<int> bubble_Sort(std::vector<int> list);
    std::vector<int> insertion_Sort(std::vector<int> list);
    std::vector<int> selection_Sort(std::vector<int> list);

    void PrintList(std::vector<int> list);  

    //prints the amount of time (in microseconds) that the last sort operation took to perform
    void PrintLastRuntime();
private:
    //assign current time at beginning of algo:
    std::chrono::high_resolution_clock::time_point startTime;
    //assign current time at end of algo:
    std::chrono::high_resolution_clock::time_point endTime;

    //difference between start and end time:
    std::chrono::high_resolution_clock::duration duration;

    void StartClock();
    void StopClock();
};