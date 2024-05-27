#include <stdio.h>

void swap(int a , int b) {
    int temp = a;
    a = b;
    b = temp;
}

void printArr(int arr[], int n) {
    for (int i = 0 ; i < n ; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int l, int r) {
    int p = arr[r];
    int i = l;
    for (int j = l; j < r; j++) {
        if (arr[j] < p) {
            swap(arr[i], arr[j]);
            i++;
        }
        swap(arr[i], arr[p]);
        return i;
    }
}

void quickSort(int arr[], int l, int r) { 
    if (l >= r) {
        return;
    }
    int p = partition(arr, l, r);
    quickSort(arr, l, p-1);
    quickSort(arr, p+1, r);
}

void main () {
    int n;
    printf("no. of elements: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0 ; i < n ; i++) {
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, n-1);
    printArr(arr, n);
}