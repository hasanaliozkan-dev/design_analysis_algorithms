import java.util.Stack;

public class StackWithArray {
    private int[] stack;
    private int top=-1;

    public StackWithArray(int size){
        stack = new int[size];
    }
    void push(int number){ stack[++top] = number;}
    int pop(){ return stack[top--]; }
    int top(){ return  stack[top];}
    int size(){ return top+1;}
    void display(){
        for (int i = top-1; i >=0 ; i--) {
            System.out.print(stack[i] + ", ");
        }
    }
    boolean isEmpty(){ return top ==-1;}


    public static void main(String[] args) {
        Stack mys = new Stack();
        StackWithArray mystack = new StackWithArray(10);
        mystack.push(0);mystack.push(1);mystack.push(2);
        mystack.push(3);mystack.push(4);mystack.push(5);
        mystack.push(6);mystack.push(7);mystack.push(8);
        mystack.display();
        System.out.println();
        System.out.println(mystack.size());
        System.out.println(mystack.isEmpty());
        int length = mystack.size();
        for (int i = 0; i < length; i++) {
            System.out.println("Popped "+mystack.pop());
        }

        System.out.println(mystack.isEmpty());
    }
}
