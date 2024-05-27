#include <stdio.h>
#define inf 999999999

void printArr(int arr[], int n) {
    for (int i = 0 ; i < n ; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int l, int m, int r) {
    int i = l, j = m, k = 0;
    int tmp[r-l+1];
    while (i < m && j < r) {
        if (arr[i] < arr[j]) {
            tmp[k++] = arr[i++];
        } else {
            tmp[k++] = arr[j++];
        }
    }

    while (i < m) {
        tmp[k++] = arr[i++];
    }

    while (j < r) {
        tmp[k++] = arr[j++];
    }

    for (i = l, j = 0 ; i < r ; i++, j++) {
        arr[i] = tmp[j];
    }
    
}

void mergeSort(int arr[], int l, int r) {
    if (l = r) {
        return;
    }
    // 0->10; l = 0 r = 10 m = 10-0/2 = 5
    // 6->10; l = 6 r = 10 m = l+ (r-l/2) = l+r/2 = 6+2 = 8
    int m = (l+r)/2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    merge(arr, l, m, r);
}

void main () {
    int n;
    printf("no. of elements: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0 ; i < n ; i++) {
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, 0, n-1);
    printArr(arr, n);
}
