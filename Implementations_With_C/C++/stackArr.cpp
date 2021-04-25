//
// Createg by  ALİ ÖZKAN on 19.05.2020.
//
#include <cstdio>
#include <cstdlib>
int *arr = NULL;
int size = 2;
int top = 0;
int pop(){
    if (arr == NULL){
        printf("This array is empty.");
        return -1;
    }
    if(top <= size/4){
        int *arr2 = (int*)malloc(sizeof(int)*size/2);
        for (int i = 0;i<size;i++) {
            arr2[i] = arr[i];
        }
        free(arr);
        arr = arr2;
        size /= 2;
    }

    return arr[--top];
}
void push(int a){
    if (arr == NULL){
        arr = (int*)malloc(sizeof(int)*2);
    }
    if (top>=size){
        int *arr2 = (int*)malloc(sizeof(int)*size*2);
        for (int i = 0;i<size;i++){
            arr2[i] = arr[i];
        }
        free(arr);
        arr = arr2;
        size *= 2;
    }
    arr[top++] = a;
}
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

