#include <stdio.h>

void hanoi(int n, char from, char to, char aux) {
    if (n==1) {
        printf("move disk 1 from %c to %c\n", from, to);
    } else {
        hanoi(n-1, from, aux, to);
        printf("move disk %d from %c to %c\n", n, from, to);
        hanoi(n-1, aux, to, from);
    }
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    return 0;
}