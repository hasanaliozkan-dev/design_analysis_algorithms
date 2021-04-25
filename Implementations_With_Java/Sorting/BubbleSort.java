import java.io.BufferedReader;

public class BubbleSort {
    public static void main(String args[]) {
        int[] x = {2, 5, 6, 3, 7, 8, 9, 4, 1};
        BubbleSort s = new BubbleSort();
        s.bubblesort(x);
        for (int i : x) {
            System.out.println(i);
        }
    }
    public void bubblesort(int [] A) // bir diziyi parametre alan fonksiyon
    {
        int tmp;

        for(int i=0; i<A.length; i++)
        {
            boolean sirali=true;
            for(int j=A.length-1 ; j>i;j--)
            {

                if(A[j-1]>A[j])
                {
                    sirali=false;
                    tmp=A[j-1];
                    A[j-1]=A[j];
                    A[j]=tmp;
                }
            }
            if(sirali)
                break;
        }
    }
}


