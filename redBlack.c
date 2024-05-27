#include <stdio.h>
#include <stdlib.h>

enum Color {RED, BLACK};

typedef struct Node {
    int data;
    int color;
    struct Node *left, *right, *parent;
} Node;

// Utility function to create a new red-black tree node
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->color = RED; // New nodes are always red initially
    node->left = node->right = node->parent = NULL;
    return node;
}

// Function to perform left rotation
void leftRotate(Node** root, Node* x) {
    Node* y = x->right;
    x->right = y->left;

    if (y->left != NULL) {
        y->left->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == NULL) {
        *root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
}

// Function to perform right rotation
void rightRotate(Node** root, Node* y) {
    Node* x = y->left;
    y->left = x->right;

    if (x->right != NULL) {
        x->right->parent = y;
    }

    x->parent = y->parent;

    if (y->parent == NULL) {
        *root = x;
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }

    x->right = y;
    y->parent = x;
}

// Function to fix violations caused by BST insertion
void fixViolation(Node** root, Node* z) {
    while (z != *root && z->parent->color == RED) {
        Node* parent = z->parent;
        Node* grandparent = z->parent->parent;

        // Case A: Parent is left child of Grand-parent
        if (parent == grandparent->left) {
            Node* uncle = grandparent->right;

            // Case 1: Uncle is RED
            if (uncle != NULL && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                z = grandparent;
            } else {
                // Case 2: z is right child
                if (z == parent->right) {
                    leftRotate(root, parent);
                    z = parent;
                    parent = z->parent;
                }

                // Case 3: z is left child
                rightRotate(root, grandparent);
                int temp = parent->color;
                parent->color = grandparent->color;
                grandparent->color = temp;
                z = parent;
            }
        } else { // Case B: Parent is right child of Grand-parent
            Node* uncle = grandparent->left;

            // Case 1: Uncle is RED
            if (uncle != NULL && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                z = grandparent;
            } else {
                // Case 2: z is left child
                if (z == parent->left) {
                    rightRotate(root, parent);
                    z = parent;
                    parent = z->parent;
                }

                // Case 3: z is right child
                leftRotate(root, grandparent);
                int temp = parent->color;
                parent->color = grandparent->color;
                grandparent->color = temp;
                z = parent;
            }
        }
    }
    (*root)->color = BLACK; // Root should always be black
}

// Function to insert a new node with given data
void insert(Node** root, int data) {
    Node* z = createNode(data);
    Node* y = NULL;
    Node* x = *root;

    // Perform standard BST insert
    while (x != NULL) {
        y = x;
        if (z->data < x->data) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    z->parent = y;

    if (y == NULL) {
        *root = z;
    } else if (z->data < y->data) {
        y->left = z;
    } else {
        y->right = z;
    }

    // Fix Red-Black Tree violations
    fixViolation(root, z);
}

// In-order traversal of the tree
void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    Node* root = NULL;

    int n, data;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter node values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insert(&root, data);
    }

    printf("In-order traversal of the Red-Black Tree:\n");
    inorder(root);
    printf("\n");

    return 0;
}

// Enter number of nodes: 5
// Enter node values:
// 10
// 20
// 30
// 15
// 25
// 