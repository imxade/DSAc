#include <stdio.h>

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i+1;
    int right = left+1;
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}    

void heapSort(int arr[], int n) {
    for (int i = (n/2)-1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n-1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void main () {
    int n;
    printf("no. of elements: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0 ; i < n ; i++) {
        scanf("%d", &arr[i]);
    }
    heapSort(arr, n);
    printArr(arr, n);
}