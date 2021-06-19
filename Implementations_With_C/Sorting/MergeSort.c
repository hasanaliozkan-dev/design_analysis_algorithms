#include <stdio.h>
  
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void merge(int arr[],int left, int middle,int right){
    int leftlength = middle -left +1;
    int rightlength = right -middle;
    int leftPart[leftlength],rightPart[rightlength];

    for (int i = 0; i < leftlength; i++)
    {
        leftPart[i] = arr[left + i];
    }
    for (int i = 0; i < rightlength; i++)
    {
        rightPart[i] = arr[middle+i+1];
    }
    int i =0,j =0,k=left;
    while (i<leftlength&&j<rightlength)     
    {
        if(leftPart[i]<=rightPart[j]){
            arr[k] = leftPart[i];
            i++;
        }else
        {
            arr[k] = rightPart[j];
            j++;
        }
        k++;
    }
    while (i<leftlength)
    {
        arr[k] = leftPart[i];
        i++;k++;
    }
     while (j<rightlength)
    {
        arr[k] = rightPart[j];
        j++;k++;
    }
    
}
void mergeSort(int arr[], int left, int right)
{
    if (left < right) {
        int middle = left + (right - left) / 2;
 
        
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
 
        merge(arr, left, middle, right);
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
    mergeSort(arr,0,n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}