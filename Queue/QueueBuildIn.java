import java.util.PriorityQueue;
public class QueueBuildIn{

    public static void main(String[] args){
        PriorityQueue<Integer> myqueue = new PriorityQueue<Integer>();
        myqueue.add(0);myqueue.add(1);myqueue.add(2);myqueue.add(3);myqueue.add(4);
        myqueue.add(5);myqueue.add(6);myqueue.add(7);myqueue.add(8);myqueue.add(9);
        int length = myqueue.size();

        for(int i = 0;i<length;i++){
            System.out.print(myqueue.remove() + ",");
        }
        System.out.println();
        System.out.println(myqueue.size());
    }
}