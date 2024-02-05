#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *createNode(char value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode != NULL) {
        newNode->data = value;
        newNode->next = NULL;
    } else {
        printf("Memory allocation failed\n");
    }
    return newNode;
}

struct Node *findNode(char tar) {
    if (head == NULL) {
        return NULL;
    }
    struct Node *tmp = head;
    do {
        if (tmp->data == tar) {
            return tmp;
        }
        tmp = tmp->next;
    } while (tmp != head);
    return NULL;
}

void insertElm(struct Node *new, struct Node *tar) {
    if (tar == NULL) {
        return;
    }
    new->next = tar->next;
    tar->next = new;
}

void insertAft(char val, char tar) {
    insertElm(createNode(val), findNode(tar));
}

struct Node *lastElm(struct Node *elm, int print) {
    struct Node *tmp = elm;
    while (tmp->next != elm) {
        tmp = tmp->next;
        if (print == 1) {
            printf("-> %c", tmp->data);
        }
    }
    return tmp;
}

void insertBeg(char value) {
    struct Node *tmp = createNode(value);
    if (head == NULL) {
        head = tmp;
        head->next = head;
    } else {
        struct Node *last = lastElm(head, 0);
        tmp->next = head;
        last->next = tmp;
        head = tmp;
    }
}


void freeElm(struct Node *tar) {
    lastElm(tar, 0)->next = tar->next;
    free(tar);
}

void del(char tar) {
    freeElm(findNode(tar));
}

void display() {
    printf("-> %c", head->data);
    lastElm(head, 1);
    printf("\n");
}

char inputChar(const char *prompt) {
    char value;
    printf("%s", prompt);
    while (scanf(" %c", &value) != 1) {
        printf("Invalid input. Try again: ");
        while (getchar() != '\n'); // Clear input buffer
    }
    return value;
}

int getUserChoice() {
    int choice;
    printf("\n1. Insert At Beginning\n2. Insert After\n3. Delete\n4. Print List\n0. Exit\n");
    printf("Enter your choice: ");
    while (scanf("%d", &choice) != 1) {
        printf("Invalid input. Try again: ");
        while (getchar() != '\n'); // Clear input buffer
    }
    return choice;
}

int main(void) {
    int userChoice;
    char value, target;

    do {
        userChoice = getUserChoice();

        switch (userChoice) {
            case 2:
                insertAft(inputChar("Enter value: "),inputChar("Enter target: "));
                break;
            case 1:
                insertBeg(inputChar("Enter value to insert at the beginning: "));
                break;
            case 3:
                del(inputChar("Enter value to delete: "));
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
        display();
    } while (userChoice != 0);

    return 0;
}
