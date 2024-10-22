// Bubble sort algorithm in C++

#include <iostream>
#include <random>
#include <chrono>
#include <fstream>
#include <vector>

// Function to print the array
void printArray(int array[], int size) {
    int i;
    for (i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void bubble_sort(int list[], int n) {
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n - 1; ++i) {
            if (list[i] > list[i + 1]) {
                int x = list[i + 1];
                list[i + 1] = list[i];
                list[i] = x;
            }
        }
    }
}

int main(int argc, const char *argv[]) {
    // Open a CSV file to store the results
    std::ofstream outfile("bubblesort_times.csv");
    outfile << "n,time_ms\n"; // CSV header

    // Random number generation setup with a fixed seed for reproducibility
    const int MAX_VALUE = 1000000;  // Fixed range for random numbers

    for (int n = 10000; n <= 100000; n += 10000) {
        std::mt19937 gen(42);
        std::uniform_int_distribution<> distrib(1, MAX_VALUE);

        std::cout << "Sorting array of size n = " << n << "...\n";

        std::vector<int> data(n);


        for (int i = 0; i < n; ++i) {
            data[i] = distrib(gen);
        }

        // Start timing using high-resolution clock
        auto start = std::chrono::high_resolution_clock::now();

        // Perform bubble sort on data
        bubble_sort(data.data(), n);

        // Stop timing
        auto end = std::chrono::high_resolution_clock::now();

        // Calculate duration
        std::chrono::duration<double, std::milli> duration = end - start;

        // Output the duration
        // std::cout << "n = " << n << ", Bubble sort took " << duration.count() << " ms.\n";

        // Write to CSV
        outfile << n << "," << duration.count() << "\n";

    }

    outfile.close();
    return 0;
}