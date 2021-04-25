import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

public class Sorting {

    public static void main(String[] args) {

         int[] nums = {12,19,77,35,88,78,59};
        printList(nums);
        nums = quicksSort(nums,0,nums.length-1);
        printList(countingSort(nums));
    }
    public static int[] lessonInsertion(int[] arr) {
        for (int i = 1; i <arr.length ; i++) {
            int temp = arr[i];
            int k;
            for(k = i;k>0 && temp<arr[k-1];k--){
                arr[k] = arr[k-1];
            }
            arr[k]=temp;
        }
        return arr;
    }

    public static void recursiveInsertion(int[] array , int length){
        if(length<=1)
            return;

        recursiveInsertion(array,length-1);
        int last = array[length-1];
        int j = length-2;
        for (;j>=0 && array[j]>last;j--)
            array[j+1] = array[j];
        array[j+1] = last;
    }
    public static int[] myInsertion (int [] arr){
        int temp;
        for (int i = 1; i <arr.length ; i++) {
            if (arr[i]<arr[i-1]){
                temp = arr[i];
                arr[i] = arr[i-1];
                arr[i-1] = temp;
                i -= 1;
            }
        }
        return arr;
    }
    public  static int[] countingSort(int arr[]){
        int max = arr[0];
        for (int i = 1; i <arr.length ; i++) {
            if (max<arr[i])
                max = arr[i];
        }
        int[] brr = new int[max+1];
        for (int i = 0; i <arr.length ; i++) {
            brr[arr[i]]++;
        }
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i <brr.length ; i++) {
            for (int j = 0; j <brr[i] ; j++) {
                result.add(i);
            }
        }
        int[] retarr = new int[result.size()];
        for (int i = 0; i <result.size() ; i++) {
            retarr[i] = result.get(i);
        }
        return retarr;

    }
    public static int partition(int arr[], int low, int high)
    {
        int pivot = arr[high];
        int i = (low-1);
        for (int j=low; j<high; j++)
        {

            if (arr[j] < pivot)
            {
                i++;

                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i+1];
        arr[i+1] = arr[high];
        arr[high] = temp;

        return i+1;
    }

    public static int[] quicksSort(int arr[], int low, int high)
    {
        if (low < high)
        {
            int pi = partition(arr, low, high);
            quicksSort(arr, low, pi-1);
            quicksSort(arr, pi+1, high);
        }
        return arr;
    }

    public static int[] mergeSort(int[] arr){
        if (arr.length<=1)
            return arr;
        int mid = arr.length/2;
        int[] left = new int[mid];
        int[] right;
        if (arr.length%2==0){
            right = new int[mid];
        }else{
            right  = new int[mid+1];
        }
        for (int i = 0; i <left.length ; i++) {
            left[i] = arr[i];
        }
        //System.arraycopy(arr, 0, left, 0, left.length);
        for (int j = 0; j <right.length ; j++) {
            right[j] = arr[mid+j];
        }
        int[] result = new int[arr.length];
        left = mergeSort(left);
        right = mergeSort(right);
        result = merge(left,right);
        return result;
    }
    public static int[] merge(int[] left,int[] right){
        int[] result = new int[left.length+right.length];
        int l = 0,r = 0,k= 0;
        while (l<left.length||r<right.length){
            if (l<left.length&&r<right.length){
                if (left[l]<right[r]){
                    result[k++] = left[l++];

                }else {
                    result[k++] = right[r++];
                }
            }
            else if(l<left.length){
                result[k++] = left[l++];
            }
            else if(r<right.length){
                result[k++] = right[r++];
            }
        }
        return result;
    }
    public static int[] myBubble(int[] arr){
        boolean isSorted = true;
        int temp;
        for (int i = 0; i <arr.length-1 ; i++) {
            for (int j = 0; j <arr.length-1 ; j++) {
                if (arr[j]>arr[j+1]){
                    isSorted= false;
                    temp = arr[j+1];
                    arr[j+1] = arr[j];
                    arr[j] = temp;
                }
            }
            if (isSorted)
                break;
        }
        return arr;
    }
    public static void recursiveBubbleSort(int[] array,int length){
        if (length ==1)
            return;
        for (int i = 0; i < length-1 ; i++) {
            if (array[i]>array[i+1]){
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                /*
                 //or
                array[i] = array[i] +array[i+1];
                array[i+1] = array[i] - array[i+1];
                array[i] = array[i] -array[i+1];*/
            }
            recursiveBubbleSort(array,length-1);
        }
    }

    public static int[] mySelection(int[] arr){
        int temp,min;
        for (int i = 0; i <arr.length-1; i++) {
            min =i;
            for (int j = i; j <arr.length ; j++)
                    if (arr[j]<arr[min])
                            min = j;

            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
        return arr;
    }

     public static void printList(int[] nums)
    {
        System.out.println(Arrays.toString(nums).replace("[","").replace("]","").replace(",",""));
        /*for(int i = 0; i < nums.length; i++)
        {
            System.out.print(nums[i] + " ");
        }*/
    }


}
