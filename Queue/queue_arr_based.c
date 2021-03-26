//
// Created by  ALİ ÖZKAN on 4.06.2020.
//
#include <stdio.h>
#include <stdlib.h>
//Use pointer to create an dynamic array queue.
int * array = NULL;   
int queue =0 , firstQueue = 0 , size = 2; //Firstqueue is the first element in the queue.
                                //Initially size is 2 but we doubled later on.
/*Removes first element in the queue and return is if exists.
If the queue is empty returns -1 and print the message.*/ 
int deque(){
    if (queue == firstQueue){
        printf("The queue is empty");
        return -1;
    
    }//If the size is less than all size we cut to half our queue.
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
    //Change the first element incrementing by firstQueue.
    return array[firstQueue++];
}
/*Adds element at the end of the queue*/
void enque(int number){
    //If queue is empty memory allocate to our queue which size is 2.
    if (array== NULL){
        array = (int*)malloc(sizeof(int)*2);
    }
    //If the queue will be full we doubled the size.
    if(queue >= size){
        size *=2;
        int * array2 =(int*)malloc(sizeof(int)*size);
        for (int i = 0; i <size/2 ; ++i)
            array2[i] = array[i];
        //We delete the old array from the memory.
        free(array);
        //We assign the new array address to our old array pointer.
        array = array2;

    }
    //Increment the first empty place pointer.
    array[queue++] = number;
}
//Cleaning up all data in our queue.
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
