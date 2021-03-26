import java.util.Stack;
public class StackBuildIn{
    public static void main(String[] args){
        Stack<Integer> mystack = new Stack<>();
        mystack.push(0);mystack.push(1);mystack.push(2);mystack.push(3);mystack.push(4);
        mystack.push(5);mystack.push(6);mystack.push(7);mystack.push(8);mystack.push(9);
        int length = mystack.size();
        
        for(int i = 0;i<length;i++){
            System.out.print(mystack.pop() + ",");
        }

        System.out.println();
        System.out.println(mystack.size());
    }
}