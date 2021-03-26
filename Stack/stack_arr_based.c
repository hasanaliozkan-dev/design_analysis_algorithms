//
// Created by  ALİ ÖZKAN on 19.05.2020.
//
#include <stdio.h>
#include <stdlib.h>

int *arr = NULL;  //Use pointer to create an dynamic array stack.
int size = 2; //Initially size is 2 but we doubled later on.
int top = 0; //Top is the toppest elemnet in our stack.
//Remove and return the topepst element in the stack. 
int pop(){
    //If is empty return -1 and print the message.
    if (arr == NULL){
        printf("This array is empty.");
        return -1;
    }
    //If the size is less then all size we cut to half our stack.
    if(top <= size/4){
        int *arr2 = (int*)malloc(sizeof(int)*size/2);
        for (int i = 0;i<size;i++) {
            arr2[i] = arr[i];
        }
        //We delete the old array from the memory.
        free(arr);
        //We assign the new array address to our old array pointer.
        arr = arr2;
        size /= 2;
    }
    //Decrement the top to reach the next item.
    return arr[--top];
}
/*Adds element at the top of the stack*/
void push(int a){
    //If stack is empty memory allocate to our stack which size is 2.
    if (arr == NULL){
        arr = (int*)malloc(sizeof(int)*2);
    }//If the stack will be full we doubled the size.
    if (top>=size){
        int *arr2 = (int*)malloc(sizeof(int)*size*2);
        for (int i = 0;i<size;i++){
            arr2[i] = arr[i];
        }
        //We delete the old array from the memory.
        free(arr);
        //We assign the new array address to our old array pointer.
        arr = arr2;
        size *= 2;
    }
    arr[top++] = a;
}//Print the all element in the stack.
void printStackArr() {
    for (int i = 0; i < top; i++) {
        printf("%d ", arr[i]);

    }
    printf("\nSize : %d \n",size);
}
int main(){

    push(10);
    push(20);
    push(30);
    printStackArr();
    push(40);
    push(50);
    printStackArr();
    printf("\npopped %d\n",pop());
    printStackArr();
    printf("\npopped %d\n",pop());
    printStackArr();
    printf("\npopped %d\n",pop());
    printStackArr();
    printf("\npopped %d\n",pop());
    printStackArr();
    printf("\npopped %d\n",pop());
    printStackArr();
    return 0;
}

