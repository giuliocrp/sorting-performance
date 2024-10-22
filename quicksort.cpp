// Quicksort algorithm in C++

#include <iostream>
#include <random>
#include <chrono>
#include <fstream>
#include <vector>

// Function to swap elements
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Function to print the array
void printArray(int array[], int size) {
    int i;
    for (i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

// Function to rearrange array (find the partition point)
int partition(int array[], int low, int high) {
    
    // Select the rightmost element as pivot
    int pivot = array[high];
    
    // Pointer for greater element
    int i = (low - 1);
    
    // Traverse through all elements
    // Compare each element with pivot
    for (int j = low; j < high; ++j) {
        if (array[j] <= pivot) {
            i++;
            
            // Swap element at i with element at j
            swap(&array[i], &array[j]);
        }
    }
    
    // Swap the pivot element with the greater element at i
    swap(&array[i + 1], &array[high]);
    
    // Return the position from where partition is done
    return (i + 1);
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        
        // Find pivot element such that
        // Element smaller than pivot are on the left
        // Element greater than pivot are on the right
        int pi = partition(array, low, high);
        
        // Recursive call on the left of pivot
        quickSort(array, low, pi - 1);
        
        // Recursive call on the right of pivot
        quickSort(array, pi + 1, high);
    }
}

int main(int argc, const char *argv[]) {
    // Open a CSV file to store the results
    std::ofstream outfile("quicksort_times.csv");
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

        // Perform quicksort on data
        quickSort(data.data(), 0, n - 1);

        // Stop timing
        auto end = std::chrono::high_resolution_clock::now();

        // Calculate duration
        std::chrono::duration<double, std::milli> duration = end - start;

        // Output the duration
        // std::cout << "n = " << n << ", QuickSort took " << duration.count() << " ms.\n";

        // Write to CSV
        outfile << n << "," << duration.count() << "\n";

    }

    outfile.close();
    return 0;
}