#include <vector>
#include <random>

#include "Sorter.h"

std::vector<int> generateRandomList(int n, int lowerLimit, int upperLimit) {
    std::random_device rd;   //obtain random seed from OS
    std::mt19937 gen(rd());  //mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(lowerLimit, upperLimit); //rand of numbers

    std::vector<int> randomList;
    for (int i = 0; i < n; ++i) {
        randomList.push_back(distrib(gen));
    }

    return randomList;
}

int main() {
    int n = 10000;
    int upperLimit = 729, lowerLimit = 0;

    int numTrialsToRun = 100;

    std::vector<int> randomNumbers = generateRandomList(n, lowerLimit, upperLimit);

    Sorter sorter;

    //bubble sort:
    std::cout << "Running bubble sort on 10,000 random numbers: " << std::endl;
    sorter.bubble_Sort(randomNumbers);
    sorter.PrintLastRuntime();

    //generate another random list:
    randomNumbers = generateRandomList(n, lowerLimit, upperLimit);

    //insertion sort:
    std::cout << "Running insertion sort on 10,000 random numbers: " << std::endl;
    sorter.insertion_Sort(randomNumbers);
    sorter.PrintLastRuntime();

    //generate another random list:
    randomNumbers = generateRandomList(n, lowerLimit, upperLimit);

    //selection sort:
    std::cout << "Running selection sort on 10,000 random numbers: " << std::endl;
    sorter.selection_Sort(randomNumbers);
    sorter.PrintLastRuntime();
}

