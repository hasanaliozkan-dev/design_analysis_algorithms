//
// Created by  ALİ ÖZKAN on 16.05.2020.
//
#include<stdio.h>
#include <stdlib.h>
struct n {
    int x;
    n*next;
    n*prev;
};
typedef n node ;
void printList(node*r){
    while (r != NULL){
        printf("%d\n",r->x);
        r = r->next;
    }
}
node * addItemOrdinary(node*r,int a){

    if (r == NULL){//if its empty.
        r = (node*)(malloc(sizeof(node)));
        r->next = NULL;
        r->prev = NULL;
        r->x = a;
        return r;
    }
    if(r->x > a){//if a is less then first item.
        //the root is changed.
        node*temp = (node*)malloc(sizeof(node));
        temp->x = a;
        temp->next =r;
        r->prev = temp;
        temp->prev = NULL;
        return temp;
    }
    node*iter = r;
    while (iter->next!= NULL && iter->next->x<a){
        iter = iter->next;
    }
    node*temp = (node*)malloc(sizeof(node));
    temp->next = iter->next;
    iter->next = temp;
    temp->prev = iter;
    if (temp->next != NULL){
        temp->next->prev = temp;
    }
    temp->x=a;
    return r;
}
node * delItem(node*r,int a){
    node*temp;
    node*iter = r;
    if(r->x == a){
        temp = r;
        r = r->next;
        free(temp);
    }
    while (iter->next != NULL && iter->next->x != a){
        iter = iter->next;
    }
    if (iter->next == NULL){//the number doesn't exist.
        return r;
    }
    temp = iter->next;
    iter->next = iter->next->next;
    if(iter->next != NULL) {
        iter->next->prev = iter;
    }
    free(temp);
    return r;


}

int main(){
    node*root;
    root = NULL;
    root = addItemOrdinary(root,400);
    root = addItemOrdinary(root,40);
    root = addItemOrdinary(root,4);
    root = addItemOrdinary(root,450);
    root = addItemOrdinary(root,50);
    printList(root);
    root = delItem(root,50);
    printList(root);
    root = delItem(root,450);
    printList(root);
}