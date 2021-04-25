//
// Created by  ALİ ÖZKAN on 10.06.2020.
//
#include <cstdio>
#include <cstdlib>
struct n {
    int data;
    n*left;
    n*right;
};
typedef n node;
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
int  main() {

    node *tree = NULL;
    tree = addItem(tree, 12);
    tree = addItem(tree, 200);
    tree = addItem(tree, 190);
    tree = addItem(tree, 213);
    tree = addItem(tree, 56);
    tree = addItem(tree, 24);
    tree = addItem(tree, 18);
    tree = addItem(tree, 27);
    tree = addItem(tree, 28);
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
    tree = delItem(tree, 21);
    tree = delItem(tree, 12);
    tree = delItem(tree, 200);
    tree = delItem(tree, 190);
    tree = delItem(tree, 213);
    tree = delItem(tree, 24);
    tree = delItem(tree, 18);
    tree = delItem(tree, 27);
    tree = delItem(tree, 28);
    tree = delItem(tree, 56);
    return 0;
}
