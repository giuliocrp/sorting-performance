# Sorting Algorithms Performance Analysis

This project compares the performance of two sorting algorithms:
**QuickSort** and **Bubble Sort**. The goal is to measure their execution
times over varying array sizes to observe their time complexities
empirically.

## QuickSort
We know that QuickSort has a time complexity of O(n log n) on average.

## Bubble Sort
Bubble Sort has a time complexity of O(n^2) in the worst case.

## Compilation

```bash
g++ quicksort.cpp -std=c++17 -o quicksort_run
g++ bubblesort.cpp -std=c++17 -o bubblesort_run
```

## Execution

```bash
./quicksort_run
./bubble_sort_run
```

You can then use the Jupyter notebook to visualize the results.