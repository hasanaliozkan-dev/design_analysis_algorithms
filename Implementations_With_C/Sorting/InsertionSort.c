#include <stdio.h>
  
void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void insertionSort(int arr[] , int n){
    for (int i = 1; i < n; i++)
    {
        int toInsert = arr[i];
        int j =i-1;
        while (j>=0 && arr[j]>toInsert)
        {
            arr[j+1] = arr[j]; 
            j--;
        }
        arr[j+1] = toInsert;
    
        
    }
    
} 

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
  

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}