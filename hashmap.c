#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;  // Global variable

struct Node *createNode(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->next = newNode->prev = NULL;
    } else {
        printf("Memory allocation failed\n");
    }
    return newNode;
}

void initHead(int value) {
    head = createNode(value);
    head->next = head->prev = head;
}

struct Node *findNode(int value) {
    if (head == NULL) {
        return NULL;
    }
    struct Node *current = head;
    do {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    } while (current != head);

    printf("%d not found\n", value);
    return NULL;
}

void insertElement(struct Node *newNode, struct Node *position) {
    if (position == NULL) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    newNode->next = position->next;
    newNode->prev = position;
    position->next = position->next->prev = newNode;
}

void insertAfter(int value, int target) {
    if (head == NULL) {
        initHead(value);
    } else {
        insertElement(createNode(value), findNode(target));
    }
}

void insertBefore(int value, int target) {
    if (head != NULL) {
        insertElement(createNode(value), findNode(target)->prev);
    }
}

void insertAtBgn(int value) {
    struct Node *newNode = createNode(value);
    if (head == NULL) {
        initHead(value);
    } else {
        insertElement(newNode, head);
        head = newNode;
    }
}

void freeElement(struct Node *position) {
    position->prev->next = position->next;
    position->next->prev = position->prev;
    free(position);
}

void delete(int target) {
    struct Node *position = findNode(target);
    if (position != NULL) {
        freeElement(position);
        if (head == position) {
            head = position->next;
        }
    }
}

void printList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    do {
        printf("%d <> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void cleanupList() {
    if (head == NULL) {
        return;
    }
    struct Node *temp = head->next;
    do {
        struct Node *next = temp->next;
        free(temp);
        temp = next;
    } while (temp != head);
}

int getUserChoice() {
    int choice;
    printf("\n1. Insert After\n2. Insert Before\n3. Insert At Beginning\n4. Delete\n5. Print List\n0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main(void) {
    int userChoice, value, target;

    do {
        userChoice = getUserChoice();

        switch (userChoice) {
            case 1:
                printf("Enter value, target: ");
                scanf("%d %d", &value, &target);
                insertAfter(value, target);
                break;
            case 2:
                printf("Enter value, target: ");
                scanf("%d %d", &value, &target);
                insertBefore(value, target);
                break;
            case 3:
                printf("Enter value to insert at the beginning: ");
                scanf("%d", &value);
                insertAtBgn(value);
                break;
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete(value);
                break;
            case 5:
                printList();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (userChoice != 0);

    cleanupList();

    return 0;
}
