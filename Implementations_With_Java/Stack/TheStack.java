import java.util.Arrays;

public class TheStack {

    private String[] stackArray;
    private int stackSize;
    private int topOfStack = -1;

    public TheStack(int stackSize){
        this.stackSize=stackSize;
        stackArray = new String[stackSize];

        Arrays.fill(stackArray,"-1");
    }
    public void displayTheStack(){

        for(int n = 0; n < 61; n++)System.out.print("-");

        System.out.println();

        for(int n = 0; n < stackSize; n++){

            System.out.format("| %2s "+ " ", n);

        }

        System.out.println("|");

        for(int n = 0; n < 61; n++)System.out.print("-");

        System.out.println();

        for(int n = 0; n < stackSize; n++){



            if(stackArray[n].equals("-1")) System.out.print("|     ");

            else System.out.print(String.format("| %2s "+ " ", stackArray[n]));

        }

        System.out.println("|");

        for(int n = 0; n < 61; n++)System.out.print("-");

        System.out.println();

    }
    public void push(String input){
        if (topOfStack +1<stackSize){
            topOfStack++;
            stackArray[topOfStack] = input;
        }
        else {
            System.out.println("Sorry the stack is full!!!");
        }
        displayTheStack();

        System.out.println("PUSH " +input+" Was added to the stack.");

    }

    public void pushMany(String multipleValues){
        String[] temp = multipleValues.split(" ");

        for (int i = 0; i <temp.length ; i++) {
            push(temp[i]);
        }
    }
    public String pop(){
        if (topOfStack>=0){
            displayTheStack();
            System.out.println("POP " +stackArray[topOfStack]+" Was removed from the stack\n");
            stackArray[topOfStack] = "-1";
            return  stackArray[topOfStack--];

        }else {
            displayTheStack();
            System.out.println("Sorry but the stack is empty!!");
            return "-1";
        }
    }
    public void popAll(){
        for (int i = topOfStack; i >=0 ; i--) {
            pop();
        }
    }
    public String peek(){
        displayTheStack();
        System.out.println("PEEK " + stackArray[topOfStack] + " Is at the top of the stack\n");
        return stackArray[topOfStack];

    }

    public static void main(String[] args) {
        TheStack theStack = new TheStack(10);
        theStack.push("hasan");
        theStack.push("ali");
        theStack.push("özkan");
        theStack.push("hasan");
        theStack.push("ali");
        theStack.peek();
        theStack.pop();
        theStack.peek();
        theStack.pushMany("hasan ali özkan büşra erturan");
        theStack.popAll();
    }
}
