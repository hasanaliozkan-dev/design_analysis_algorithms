//
// Created by  ALİ ÖZKAN on 4.06.2020.
//
#include <stdio.h>
#include <stdlib.h>
struct n{
    int data;
    n*next;
};
typedef n node ;
node*root = NULL;
node*last = NULL;
void enque(int a){
    if (root == NULL){
        root = (node*)malloc(sizeof(node));
        root->data = a;
        root->next = NULL;
        last = root;
    }else {
        last->next = (node*)malloc(sizeof(node));
        last->next->data = a;
        last = last->next;
        last->next = NULL;
    }
}
int deque(){
    if (root == NULL){
        printf("The queue is empty");
        return -1;
    }
    int rvalue = root->data;
    node*temp = root;
    root = root->next;
    free(temp);
    return rvalue;
}
int main(){

    enque(10);
    printf("%d",deque());
    return 0;
}

