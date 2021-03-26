//
// Created by  ALİ ÖZKAN on 20.05.2020.
//
#include <stdio.h>
#include <stdlib.h>
typedef struct n{
    int data;
    struct n * next;
} node;
//Remove the toppest element in the stack.
int pop(node*root){
    //If empty is null return -1 and print the message.
    if (root == NULL){
        printf("The stack is empty!!");
        return -1;
    }
    //If the stack has one element remove it.
    if (root ->next == NULL){
        int rvalue = root->data;
        free(root);
        return rvalue;
    }
    //Othervise iterate over the ll and remove the last element.
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
/*Add item in the stack*/
node* push(node*root,int a) {
    //If the stack is empty we create it in here.
    if (root == NULL) {
        //Allocate memory size of node.
        root = (node *) malloc(sizeof(node));
        root->data = a;
        root->next = NULL;
        return root;
    }
    //Otherwise iterate over the last item in the ll and set next item to be added.
    node *iter = root;
    while (iter->next != NULL) {
       iter = iter->next;
    }
    node *temp = (node *) malloc(sizeof(node));
    temp->data = a;
    temp->next = NULL;
    iter->next = temp;
    return root;
}//Iterate over the list and print the item.
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