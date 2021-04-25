//
// Created by  ALİ ÖZKAN on 4.06.2020.
//
#include <stdio.h>
#include <stdlib.h>
int * array = NULL;
int queue =0 , firstQueue = 0 , size = 2;
int deque(){
    if (queue == firstQueue){
        printf("The queue is empty");
        return -1;
    }
    if (queue-firstQueue<=size/4){
        int*array2 = (int*)malloc(sizeof(int)*size/2);
        for (int i = 0; i <queue-firstQueue ; ++i) {
            array2[i] = array[firstQueue+i];
        }
        queue= queue-firstQueue;
        firstQueue = 0;
        free(array);
        array=array2;
        size= size/2;
    }
    return array[firstQueue++];
}
void enque(int number){
    if (array== NULL){
        array = (int*)malloc(sizeof(int)*2);
    }
    if(queue >= size){
        size *=2;
        int * array2 =(int*)malloc(sizeof(int)*size);
        for (int i = 0; i <size/2 ; ++i)
            array2[i] = array[i];
        free(array);
        array = array2;

    }
    array[queue++] = number;
}
void clean(){
    if(firstQueue!=0){
        for (int i = 0; i <size ; ++i) {
            array[i] = array[i+firstQueue];
        }
        queue = queue-firstQueue;
        firstQueue = 0;
    }
}
int main(){
    for (int i = 1; i <21 ; ++i) {
        enque(i*10);
    }
    printf("boyut: %d queue: %d first queue : %d\n",size,queue,firstQueue);
    for (int j = 0; j <13 ; ++j) {
        printf("%d\n", deque());
    }
    printf("boyut: %d queue: %d first queue : %d\n",size,queue,firstQueue);
    for (int k = 1; k <21 ; ++k) {
        enque(k*30);
    }
    printf("boyut: %d queue: %d first queue : %d\n",size,queue,firstQueue);
    for (int l = 0; l <30 ; ++l) {
        printf("%d\n",deque());
    }
    printf("boyut: %d queue: %d first queue : %d\n",size,queue,firstQueue);





    return 0;
}
