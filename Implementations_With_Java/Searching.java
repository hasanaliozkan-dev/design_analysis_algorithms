public class Searching {

    public static boolean LineerSearch(int[] arr ,int number){
        for (int item:arr) {
            if (item == number)
                return true;
        }
        System.out.println("Given a sorted array the worst case is n steps that's mean complexity is O(n)");
        return false;
    }
    public static boolean BinarySearch(int arr[],int number){
        int low = 0,high = arr.length-1;
        while (low<=high){
            int mid = (low+high)/2;
            if (arr[mid]<number)
                low = mid+1;
            else if(arr[mid]>number)
                high = mid-1;
            else
                return true;
        }
        System.out.println("Given a sorted array the worst case is log(n) steps that's mean complexity is O(log(n))");
        return false;

    }
    
}
