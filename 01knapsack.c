#include <stdio.h>

// A utility function to return the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Returns the maximum value that can be put in a knapsack of capacity W
int knapsack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[n + 1][W + 1];

    // Build table K[][] in bottom-up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    // K[n][W] holds the result
    return K[n][W];
}

int main() {
    int n, W;
    
    // Input the number of items
    printf("Enter number of items: ");
    scanf("%d", &n);
    
    int val[n], wt[n];
    
    // Input the weights and values of the items
    printf("Enter value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d - Value: ", i + 1);
        scanf("%d", &val[i]);
        printf("Item %d - Weight: ", i + 1);
        scanf("%d", &wt[i]);
    }
    
    // Input the capacity of the knapsack
    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);

    // Calculate the maximum value that can be put in the knapsack
    int maxValue = knapsack(W, wt, val, n);

    // Output the result
    printf("Maximum value in knapsack = %d\n", maxValue);
    
    return 0;
}
