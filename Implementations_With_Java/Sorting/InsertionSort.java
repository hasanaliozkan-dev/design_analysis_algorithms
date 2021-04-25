public class InsertionSort {
    public static void main(String [] args)
    {
        int[] nums = {31,1,56,33,777,123,25,15,17,20,11,10,1,23,3};
        InsertionSort dz = new InsertionSort();
        dz.Sort(nums);
        dz.print(nums);
    }

    private void Sort(int[] nums){
        int temp = 0;
        int len = nums.length;
        for(int i = 1; i < len; i++)
        {
            if(nums[i] < nums[i-1])
            {
                temp = nums[i];
                nums[i] = nums[i-1];
                nums[i-1] = temp;
                i = 1;
            }
        }
    }
    private void print(int[] nums)
    {
        for(int i = 0; i < nums.length; i++)
        {
            System.out.print(nums[i] + " ");
        }
    }
}
