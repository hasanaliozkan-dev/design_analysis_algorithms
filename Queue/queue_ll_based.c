//
// Created by  ALİ ÖZKAN on 4.06.2020.
//
#include <stdio.h>
#include <stdlib.h>
/*Create our node type as a struct which has a data value and point itself(next).*/
typedef struct n{
    int data;
    struct n*next;
}node;
//Initially assign null to root it changes after.
node*root = NULL;
//Initially assign null to last it changes after.
node*last = NULL;
//returns whether queue is empty or not by checking the root.
int isEmpty(node*root){return root ==NULL;} 
//return the toppest element of the stack.
int peek(node * root){
    if(isEmpty(root)){
        printf("The queue is empty.");
        return -1;
    }
    return root->data;
}
/*Adds element at the end of the queue*/
void enque(int a){
    //If we add the first element we put the our element to root->data.
    if (root == NULL){
        //Allocate memory sized by node.
        root = (node*)malloc(sizeof(node));
        root->data = a;
        //set root next to null.
        root->next = NULL;
        //change last pointer position to the root.
        last = root;
    }
    //Otherwise we skipped the assign to root we directly add element by usingg last pointer.
    else{
        last->next = (node*)malloc(sizeof(node));
        last->next->data = a;
        last = last->next;
        last->next = NULL;
    }
}
/*Remove element and return it which is the frontest in our queue.*/
int deque(){
    //If queue is empty returns -1 and print the message.
    if (root == NULL){
        printf("The queue is empty");
        return -1;
    }
    //Otherwise take root->data and remove root node from the queue.
    int rvalue = root->data;
    node*temp = root;
    root = root->next;
    free(temp);
    return rvalue;
}
//seraching for element whether in the queue or not.
int search(node*root , int data){
    if(isEmpty(root)){
        printf("The stack is empty.");
        return-1;
    }
    node * iter = root;
    while(iter->next != NULL){
        if (iter->data == data){return 1;}
    }
    return 0;
}

int main(){
    for(int i = 0;i<10;i++){
        enque(i*10);
    }
   for(int i = 0;i<10;i++){
        printf("Dequeue -> %d\n",deque());
    }
     
    return 0;
}

