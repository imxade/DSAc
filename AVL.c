#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node *right, *left;
};

struct Node* createNode(char data) {
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->right = newNode->left = NULL;
  return newNode;
}

int max(int a, int b) {
  return (a > b) ? a : b;
}

int getHeight(struct Node *root) {
  if (root == NULL) {
    return 0;
  }
  return 1 + max(getHeight(root->right), getHeight(root->left));
}

int getBalFactor(struct Node *root) {
  return getHeight(root->left) - getHeight(root->right);
}

struct Node *rotateLeft(struct Node *root) {
  struct Node *x = root->right;
  /*
    below x->left instead of root->left
    very important
    for reason put 123456 as input in order
  */
  root->right = x->left;
  x->left = root;
  return x;  
}

struct Node *rotateRight(struct Node *root) {
  struct Node *x = root->left;
  root->left = x->right;
  x->right = root;
  return x;  
}

struct Node *balNode(struct Node *root) {
    int balFactor = getBalFactor(root);

    if (balFactor > 1) {
      if (getBalFactor(root->left) < 0) {
        root->left = rotateLeft(root->left);
      }
      return rotateRight(root);
    }
    else if (balFactor < -1) {
      if (getBalFactor(root->right) > 0) {
        root->right = rotateRight(root->right);
      }
        return rotateLeft(root);
    }
    return root;
}


struct Node *insert(struct Node *root, char data) {
  if (root == NULL) {
    return createNode(data);
  }
  else if (data < root->data) {
    root->left = insert(root->left, data);
  }
  else if (data > root->data) {
    root->right = insert(root->right, data);
  }
  return balNode(root);
}


void inOrderTrav(struct Node *root) {
  if (root == NULL) {
    return;
  }
  inOrderTrav(root->left);
  printf("%c ", root->data);
  inOrderTrav(root->right);
}

int main(){
  char a;
  struct Node *root = NULL;
  while (1) {
  printf("element to insert: ");
  scanf(" %c", &a);
  root = insert(root, a);
  inOrderTrav(root);
  printf("\n");
  }
}