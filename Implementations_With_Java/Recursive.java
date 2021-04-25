public class Recursive {
    public static void f ( int n){
        if (n>=1){
            f(n-1);
            System.out.print(n+" ");
        }
    }
    public static int factorial(int n){
        if (n == 0)
            return 1;
        else
            return n*factorial(n-1);
    }
    public static int fibonacci(int n){
        if (n ==0)
            return 0;
        else if (n==1)
            return 1;
        else
            return fibonacci(n-1)+fibonacci(n-2);

    }
    public static int power(int base,int pow){
        if (pow ==0)
            return 1;
        else
            return base*power(base,pow-1);
    }
    public static int smartPower(int base,int pow){
        if (pow==0)
            return 1;
        int halfPower = power(base,pow/2);
        if (pow%2==0)
            return halfPower*halfPower;
        else
            return base*halfPower*halfPower;


    }
    public static int combs(int n,int r){
        if (n==r||r==0)
            return 1;
        else
            return combs(n-1,r) + combs(n-1,r-1);
    }

    public static void main(String[] args) {
        f(10);
        Math.pow(3,4);
        System.out.println();
        System.out.println(factorial(4));
        System.out.println();
        System.out.println(fibonacci(4));
        System.out.println();
        System.out.println(power(3,2));
        System.out.println();
        System.out.println(combs(4,4));
        System.out.println();
        System.out.println(smartPower(9,2));
    }
}
