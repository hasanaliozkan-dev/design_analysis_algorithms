//
// Created by  ALİ ÖZKAN on 20.05.2020.
//
#include <stdio.h>
#include <stdlib.h>
struct n{
    n * next;
    int data;
};
typedef n node ;
int pop(node*root){
    if (root == NULL){
        printf("The stack is empty!!");
        return -1;
    }
    if (root ->next == NULL){
        int rvalue = root->data;
        free(root);
        return rvalue;
    }
    node*iter = root;
    while (iter->next->next != NULL){
        iter = iter->next;
    }

    node*temp = iter->next;
    int rvalue = temp->data;
    free(temp);
    iter->next = NULL;
    return rvalue;

}

node* push(node*root,int a) {
    if (root == NULL) {
        root = (node *) malloc(sizeof(node));
        root->data = a;
        root->next = NULL;
        return root;
    }
    node *iter = root;
    while (iter->next != NULL) {
        iter = iter->next;
    }
    node *temp = (node *) malloc(sizeof(node));
    temp->data = a;
    temp->next = NULL;
    iter->next = temp;
    return root;
}
void printList(node*r){
    while (r != NULL){
        printf("%d\n",r->data);
        r = r->next;
    }
}

int main(){
    node*s = NULL;
    s = push(s,10);
    s = push(s,20);
    s = push(s,30);
    printList(s);
    printf("popped %d \n",pop(s));
    printf("popped %d \n",pop(s));
    printf("popped %d \n",pop(s));
    printList(s);
    return 0;
}