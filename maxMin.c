#include <stdio.h>

// Following could've been done with array
typedef struct {
    int max;
    int min;
} pair;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

pair maxMin(int arr[], int l, int r) {
    pair res, left, right;
    if (l == r || l == r-1) {
        res.max = max(arr[l], arr[r]);
        res.min = min(arr[l], arr[r]);
        return res;
    }
    int mid = (l+r)/2;
    left = maxMin(arr, l, mid);
    right = maxMin(arr, mid+1, r);
    res.max = max(left.max, right.max);
    res.min = min(left.min, right.min);
    return res;
}

void main() {
    int n;
    printf("no. of elems: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    pair res = maxMin(arr, 0, n-1);
    printf("max: %d, min: %d\n", res.max, res.min);
}