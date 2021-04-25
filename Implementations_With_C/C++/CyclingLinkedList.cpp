//
// Created by  ALİ ÖZKAN on 16.05.2020.
//
#include<cstdio>
#include <cstdlib>

struct n{
    int x;
    n*next;
};
typedef n node ;
void printList(node*r){
    node*iter;
    printf("%d",iter);
    iter = iter->next;
    while (iter != r){
        printf("%d\n",iter->x);
        iter = iter->next;
    }
}
void addItem(node*r,int a){
    node*iter = r;
    while (iter->next !=r){
        iter = iter->next;
    }
    iter->next = (node*)(malloc(sizeof(node)));
    iter->next->x = a;
    iter->next->next = r;
}
node * addItemOrdinary(node*r,int a){

    if (r == NULL){//if its empty.
        r = (node*)(malloc(sizeof(node)));
        r->next = r;
        r->x = a;
        return r;
    }
    if(r->x > a){//if a is less then first item.
        //the root is changed.
        node*temp = (node*)malloc(sizeof(node));
        temp->x = a;
        temp->next =r;
        node*iter = r;
        while (iter->next != r){
            iter = iter->next;
        }
        iter->next = temp;
        return temp;
    }
    node*iter = r;
    while (iter->next!= r && iter->next->x<a){
        iter = iter->next;
    }
    node*temp = (node*)malloc(sizeof(node));
    temp->next = iter->next;
    iter->next = temp;
    temp->x=a;
    return r;
}
node * delItem(node*r,int a){
    node*temp;
    node*iter = r;
    if(r->x == a){
        while (iter->next!= r){
            iter = iter->next;
        }
        iter ->next = r->next;
        free(r);
        return iter->next;
    }
    while (iter->next != r && iter->next->x != a){
        iter = iter->next;
    }
    if (iter->next == r){//the number doesnt exist.
        return r;
    }
    temp = iter->next;
    iter->next = iter->next->next;
    free(temp);
    return r;


}

int main(){
    node*root;
    root =NULL;
    root = addItemOrdinary(root,400);
    root = addItemOrdinary(root,40);
    root = addItemOrdinary(root,4);
    root = addItemOrdinary(root,450);
    root = addItemOrdinary(root,50);
    printList(root);
    root = delItem(root,50);
    printList(root);

}
