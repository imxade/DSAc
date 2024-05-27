#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>

// Swap function using pointers
void swap_ptr(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Swap function using array and indices
void swap_arr(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Partition function for Quick Sort using pointer swap
int partition_ptr(int arr[], int l, int r) {
    int pivot = arr[r];
    int i = l - 1;

    for (int j = l; j < r; j++) {
        if (arr[j] < pivot) {
            i++;
            swap_ptr(&arr[i], &arr[j]);
        }
    }
    swap_ptr(&arr[i + 1], &arr[r]);
    return i + 1;
}

// Partition function for Quick Sort using array swap
int partition_arr(int arr[], int l, int r) {
    int pivot = arr[r];
    int i = l - 1;

    for (int j = l; j < r; j++) {
        if (arr[j] < pivot) {
            i++;
            swap_arr(arr, i, j);
        }
    }
    swap_arr(arr, i + 1, r);
    return i + 1;
}

// Quick Sort using pointer swap
void quickSort_ptr(int arr[], int l, int r) {
    if (l < r) {
        int p = partition_ptr(arr, l, r);
        quickSort_ptr(arr, l, p - 1);
        quickSort_ptr(arr, p + 1, r);
    }
}

// Quick Sort using array swap
void quickSort_arr(int arr[], int l, int r) {
    if (l < r) {
        int p = partition_arr(arr, l, r);
        quickSort_arr(arr, l, p - 1);
        quickSort_arr(arr, p + 1, r);
    }
}

// Function to generate an array with random elements
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000; // Random number between 0 and 9999
    }
}

// Function to copy an array
void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

// Function to get memory usage in kilobytes
long getMemoryUsage() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return usage.ru_maxrss; // Memory usage in kilobytes
}

int main() {
    int n = 10000; // Size of the array
    int arr[n], arr_copy[n];
    clock_t start, end;
    double time_taken;
    long mem_usage;

    // Seed the random number generator
    srand(time(0));

    // Generate a random array
    generateRandomArray(arr, n);

    // Benchmark Quick Sort with pointer swap
    copyArray(arr, arr_copy, n);
    start = clock();
    quickSort_ptr(arr_copy, 0, n - 1);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    mem_usage = getMemoryUsage();
    printf("Quick Sort with pointer swap took %f seconds and used %ld KB of memory\n", time_taken, mem_usage);

    // Benchmark Quick Sort with array swap
    copyArray(arr, arr_copy, n);
    start = clock();
    quickSort_arr(arr_copy, 0, n - 1);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    mem_usage = getMemoryUsage();
    printf("Quick Sort with array swap took %f seconds and used %ld KB of memory\n", time_taken, mem_usage);

    return 0;
}
