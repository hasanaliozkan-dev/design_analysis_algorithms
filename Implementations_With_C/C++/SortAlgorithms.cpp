//
// Created by  ALİ ÖZKAN on 16.06.2020.
//
#include <stdio.h>
#include <stdlib.h>
void SelectionSort(int arr[],int n){
    int tmp,min;
    for (int i = 0; i <n-1 ; ++i) {
        min= i;
        for (int j = 0; j <n ; ++j) {
            if (arr[i]<arr[min]){
                min = j;
            }
            
        }
        tmp = arr[i];
        arr[i] = arr[min];
        arr[min] = tmp;
    }
    for (int k = 0; k <n ; ++k) {
        printf("%d , ",arr[k]);

    }
}
int main (){
    int deneme[] = {10,12,23,34,454,6,5,77,78,79,75,1};
    printf("%d",SelectionSort(deneme,12));

    return 0;
}
