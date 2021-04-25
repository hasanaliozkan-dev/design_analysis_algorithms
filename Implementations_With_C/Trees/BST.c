//
// Created by  ALİ ÖZKAN on 10.06.2020.
//
#include <stdio.h>
#include <stdlib.h>
#define COUNT 10
typedef struct Node {
    int data;
    struct Node*left;
    struct Node*right;
} node;



node * addItem(node*tree,int number) {
    if (tree == NULL){
        node *root = (node *) malloc(sizeof(node));
        root->left = NULL;
        root->right = NULL;
        root->data = number;
        return root;
    }
    if (tree->data <= number){
        tree->right = addItem(tree->right, number);
        return tree;
    }
    tree->left = addItem(tree->left,number);
    return tree;
}
void traverseLNR(node*tree){
    if(tree == NULL){
        return;
    }
    traverseLNR(tree->left);
    printf("%d  ",tree->data);
    traverseLNR(tree->right);
}
void traverseRNL(node*tree){
    if (tree==NULL)
        return;
    traverseRNL(tree->right);
    printf("%d  ",tree->data);
    traverseRNL(tree->left);
}
int findItem(node*tree,int number){
    if (tree==NULL){
        return -1;
    }
    if (tree->data == number)
        return 1;
    if(findItem(tree->right,number) == 1)
        return 1;
    return -1;
}
int max(node*tree){
    while (tree->right != NULL){
        tree = tree->right;
    }
    return tree->data;
}
int min (node*tree){
    while (tree->left!= NULL){
        tree = tree->left;
    }
    return tree->data;
}
node* delItem(node*tree,int number){
    if(tree == NULL)
        return NULL;
    if (tree->data == number){
        if (tree->left == NULL && tree->right == NULL)
            return NULL;
        if (tree->right!= NULL){
            tree->data = min(tree->right);
            tree->right = delItem(tree->right,min(tree->right));
            return tree;
        }
        tree->data = max(tree->left);
        tree->left = delItem(tree->left,max(tree->left));
        return tree;
    }
    if (tree->data<number){
        tree->right= delItem(tree->right,number);
        return tree;
    }
    tree->left = delItem(tree->left,number);
    return tree;
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

        
    printf("%d\n", root->data);
  
    // Process left child
    print2DUtil(root->left, space);
}  
// Wrapper over print2DUtil()
void print2D(struct Node *root)
{
   // Pass initial space count as 0
   print2DUtil(root, 0);
}
int  main() {

    node *tree = NULL;
    tree = addItem(tree, 12);
    tree = addItem(tree, 15);
    tree = addItem(tree, 10);
    tree = addItem(tree, 11);
    tree = addItem(tree, 8);
    tree = addItem(tree, 6);
    tree = addItem(tree, 9);
    printf("\nali\n");
    traverseLNR(tree);
    printf("\n");
    traverseRNL(tree);
    printf("\n");
    printf("%d", findItem(tree, 28));
    printf("\n");
    printf("Max value : %d", max(tree));
    printf("\n");
    printf("Min value : %d", min(tree));
    printf("\n");
    print2D(tree);
    return 0;
}
