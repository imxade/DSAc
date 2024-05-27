#include <stdio.h>

typedef struct {
    int weight;
    int value;
    float ratio;
} Item;

void swap(Item* a, Item* b) {
    Item tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort(Item arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].ratio < arr[j].ratio) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

float fractionalKnapsack(int W, Item arr[], int n) {
    sort(arr, n);
    float totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (W <= 0) {
            break;
        }
        if (arr[i].weight <= W) {
            totalValue += arr[i].value;
            W -= arr[i].weight;
        } else {
            totalValue += arr[i].ratio * W;
            break;
        }
    }
    return totalValue;
}

int main() {
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);
    Item arr[n];
    printf("Enter weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].weight, &arr[i].value);
        arr[i].ratio = arr[i].value / arr[i].weight;
    }
    printf("Enter maximum capacity of knapsack: ");
    scanf("%d", &W);

    double maxValue = fractionalKnapsack(W, arr, n);
    printf("Maximum value in knapsack = %.2f\n", maxValue);
    return 0;
}