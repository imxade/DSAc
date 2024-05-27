#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int deadline;
    int profit;
} Job;

void swap(Job* a, Job* b) {
    Job tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort(Job arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].profit < arr[j].profit) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

void jobScheduling(Job jobs[], int n) {
    sort(jobs, n);

    int result[n];
    int slot[n];
    for (int i = 0; i < n; i++) slot[i] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slot[j] == 0) {
                result[j] = i;
                slot[j] = 1;
                break;
            }
        }
    }

    printf("Selected jobs: ");
    for (int i = 0; i < n; i++)
        if (slot[i])
            printf("%d ", jobs[result[i]].id);
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of jobs: ");
    scanf("%d", &n);
    Job jobs[n];
    for (int i = 0; i < n; i++) {
        printf("Enter deadline and profit of Job %d: ", i);
        scanf("%d %d", &jobs[i].deadline, &jobs[i].profit);
        jobs[i].id = i;
    }

    jobScheduling(jobs, n);
    return 0;
}
