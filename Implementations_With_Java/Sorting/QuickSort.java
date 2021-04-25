public class QuickSort {
    public static void quickSort(int A[],int p, int r)
    {
        int q;
        if(p<r)
        {
            q=partition(A,p, r);
            quickSort(A,p, q-1);
            quickSort(A,q+1, r);
        }
    }
    public static int partition(int A[],int p, int r){
        int tmp;
        int x = A[r];
        int i = p-1;

        for(int j=p; j<=r-1; j++)
        {
            if(A[j]<=x)
            {
                i++;
                tmp=A[i];
                A[i]=A[j];
                A[j]=tmp;
            }
        }
        tmp=A[i+1];
        A[i+1]=A[r];
        A[r]=tmp;
        return i+1;
    }

    public static void main(String[] args) {
        int[] x = {2, 5, 6, 3, 7, 8, 9, 4, 1};
        QuickSort Qs = new QuickSort();
        QuickSort.quickSort(x,0,x.length-1);
        for (int i : x) {
            System.out.println(i);
        }
        

    }
}
