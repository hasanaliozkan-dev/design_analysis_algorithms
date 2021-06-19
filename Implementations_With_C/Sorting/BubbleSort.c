#include <stdio.h>

  
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int arr[] ,int n){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 1; j < n-i; j++)
        {
            if (arr[j-1]>arr[j])
            {
                swap(&arr[j-1],&arr[j]);
            }
        }
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
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}