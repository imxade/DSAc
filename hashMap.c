#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int key;
    struct Node *next;
};

struct Node *createNewnode(int data, int key) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

int n;

int fHash(int data) {
    return data % n;
}

void insert(int data, int key, struct Node *table[]) {
    int index = fHash(key);
    struct Node *newNode = createNewnode(data, key);

    if (table[index] == NULL) {
        table[index] = newNode;
        return;
    }

    struct Node *temp = table[index];
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

struct Node *search(int key, struct Node *table[]) {
    int index = fHash(key);
    struct Node *temp = table[index];
    while (temp != NULL) {
        if (temp->key == key) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void del(int key, struct Node *table[]) {
    int index = fHash(key);
    struct Node *temp = table[index];

    if (temp != NULL && temp->key == key) {
        table[index] = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->next != NULL && temp->next->key != key) {
        temp = temp->next;
    }

    if (temp != NULL && temp->next != NULL) {
        struct Node *toDelete = temp->next;
        temp->next = toDelete->next;
        free(toDelete);
    }
}

void printTable(struct Node *table[]) {
    for (int i = 0; i < n; i++) {
        struct Node *temp = table[i];
        printf("[%d]: ", i);
        while (temp != NULL) {
            printf("(%d, %d) -> ", temp->key, temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    struct Node *table[n];

    while (1) {
        int data, key, choice;
        printf("1. Insert\n2. Delete\n3. Search\n4. Print\n5. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("key, data: ");
                scanf("%d %d", &key, &data);
                insert(data, key, table);
                break;
            case 2:
                printf("key: ");
                scanf("%d", &key);
                del(key, table);
                break;
            case 3:
                printf("key: ");
                scanf("%d", &key);
                struct Node *result = search(key, table);
                if (result != NULL) {
                    printf("Data for key %d: %d\n", key, result->data);
                } else {
                    printf("Key %d not found.\n", key);
                }
                break;
            case 4:
                printTable(table);
                break;
            case 5:
                exit(0);
        }
    }

    return 0;
}
