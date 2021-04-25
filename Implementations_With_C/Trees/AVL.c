// Created by  ALİ ÖZKAN on 10.06.2020.

#include <stdio.h>
#include <stdlib.h>

#define COUNT 10;
// Create Node
struct Node {
  int key; //Info in the node
  struct Node *left; //Left child
  struct Node *right;//Right child
  int height; //The height of the current node to checking balanced.
};

int max(int a, int b);

// Returns the height of the curren node.
int height(struct Node *N) {
  if (N == NULL)
    return 0;
  return N->height;
}

int max(int a, int b) {
  return (a > b) ? a : b;
}

// Creates and returns new node with given key.
struct Node *newNode(int key) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node)); // memory allocation for node 
  //Assign node properties.
  node->key = key; 
  node->left = NULL;
  node->right = NULL;
  node->height = 1;//Initially 1 becaues we have 1 node.
  return (node);
}

// Right rotate
struct Node *rightRotate(struct Node *y) {
  //To keep current node->left.
  struct Node *x = y->left;
  //To keep current node->right;
  struct Node *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}

// Left rotate
struct Node *leftRotate(struct Node *x) {
  struct Node *y = x->right;
  struct Node *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}

// Get the balance factor which supposed to be between -1 and 1.
int getBalance(struct Node *N) {
  if (N == NULL)
    return 0;
    //We can also use absolute method an looking for just difference is greater than or equal 1.
    //But this way is more efficient.
  return height(N->left) - height(N->right);
}

// Insert node
struct Node *insertNode(struct Node *node, int key) {
  // Find the correct position to insertNode the node and insertNode it
  if (node == NULL)
    return (newNode(key));
    //Looking for the position. Is key less or greater than current node->key?
  if (key < node->key)
    node->left = insertNode(node->left, key);
  else if (key > node->key)
    node->right = insertNode(node->right, key);
  else
    return node;

  // Update the balance factor of each node

  node->height = 1 + max(height(node->left),
               height(node->right));
  // Balance the tree
  int balance = getBalance(node);
  //Left-Left Case
  if (balance > 1 && key < node->left->key)
    return rightRotate(node);
  //Right-Right Case
  if (balance < -1 && key > node->right->key)
    return leftRotate(node);
  //Left_Right Case
  if (balance > 1 && key > node->left->key) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }
  //Right-Left Case
  if (balance < -1 && key < node->right->key) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  return node;
}
//Finds node which has the minimum value.(The most left node.)
struct Node *minValueNode(struct Node *node) {
  struct Node *current = node;
    //Go thorugh the most left element.
  while (current->left != NULL)
    current = current->left;
    //And return it.
  return current;
}

// Delete a nodes
struct Node *deleteNode(struct Node *root, int key) {
  // Find the node and delete it
  if (root == NULL)
    return root;
    //Looking for the position. Is key less or greater than current node->key?
  if (key < root->key)
    root->left = deleteNode(root->left, key);

  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  else {
    if ((root->left == NULL) || (root->right == NULL)) {
      struct Node *temp = root->left ? root->left : root->right;

      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else
        *root = *temp;
      free(temp);
    } else {
      struct Node *temp = minValueNode(root->right);

      root->key = temp->key;

      root->right = deleteNode(root->right, temp->key);
    }
  }

  if (root == NULL)
    return root;

  // Update the balance factor of each node and
  // balance the tree
  root->height = 1 + max(height(root->left),
               height(root->right));

  int balance = getBalance(root);
  if (balance > 1 && getBalance(root->left) >= 0)
    return rightRotate(root);

  if (balance > 1 && getBalance(root->left) < 0) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  if (balance < -1 && getBalance(root->right) <= 0)
    return leftRotate(root);

  if (balance < -1 && getBalance(root->right) > 0) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}

// Print the tree
void printPreOrder(struct Node *root) {
  if (root != NULL) {
    printf("%d ", root->key);
    printPreOrder(root->left);
    printPreOrder(root->right);
  }
}
// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(struct Node *root, int space)
{
    // Base case
    if (root == NULL)
        return;
  
    // Increase distance between levels
    space += COUNT;
  
    // Process right child first
    print2DUtil(root->right, space);
  
    // Print current node after space
    // count
    printf("\n");
    int i = COUNT;
    while(i<space){
        printf(" ");
        i++;
    }

        
    printf("%d\n", root->key);
  
    // Process left child
    print2DUtil(root->left, space);
}  
// Wrapper over print2DUtil()
void print2D(struct Node *root)
{
   // Pass initial space count as 0
   print2DUtil(root, 0);
}
int main() {
  struct Node *root = NULL;

  root = insertNode(root, 12);
  root = insertNode(root, 15);
  root = insertNode(root, 10);
  root = insertNode(root, 11);
  root = insertNode(root, 8);
  root = insertNode(root, 6);
  root = insertNode(root, 9);
  print2D(root);
  printPreOrder(root);


  return 0;
}
