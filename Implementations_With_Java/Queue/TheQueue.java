import java.util.Arrays;

public class TheQueue {

    private String queueArray[];
    private int queueSize;
    private int front,rear,numberOfItems= 0;
    public TheQueue(int queueSize){
        this.queueSize = queueSize;
        queueArray = new String[queueSize];
        Arrays.fill(queueArray,"-1");
    }
    public void displayTheQueue(){

        for(int n = 0; n < 61; n++)System.out.print("-");

        System.out.println();

        for(int n = 0; n < queueSize; n++){

            System.out.format("| %2s "+ " ", n);

        }

        System.out.println("|");

        for(int n = 0; n < 61; n++)System.out.print("-");

        System.out.println();

        for(int n = 0; n < queueSize; n++){



            if(queueArray[n].equals("-1")) System.out.print("|     ");

            else System.out.print(String.format("| %2s "+ " ", queueArray[n]));

        }

        System.out.println("|");

        for(int n = 0; n < 61; n++)System.out.print("-");

        System.out.println();

    }
    public void  insert(String input){
        if (numberOfItems+1 <= queueSize){
            queueArray[rear] = input;
            rear++;
            numberOfItems++;
            System.out.println("INSERT " +input+ " was added to the queue\n");
        }else {
            System.out.println("Sorry the queue is full!!");
        }
    }
    public void insertMany(String multipleInput){
        String[] temp = multipleInput.split(" ");
        for (int i = 0; i <temp.length ; i++) {
            insert(temp[i]);
        }
    }
    public void remove(){
        if (numberOfItems>0){
            System.out.println("REMOVE "+ queueArray[front]+" was removed from the queue\n");
            queueArray[front] = "-1";
            front++;
            numberOfItems--;
            rear--;
        }
        else {
            System.out.println("Sorry the queue is empty!!");
        }
    }
    public void peek(){
        System.out.println("The first element is " + queueArray[front]);
    }

    public void priorityInsert(String input){
        int i;
        if (numberOfItems==0){
            insert(input);
        }
        else {
            for (i = numberOfItems-1; i>=0 ; i--) {
                if (Integer.parseInt(input)>Integer.parseInt(queueArray[i])){
                    queueArray[i+1] = queueArray[i];
                }else break;
            }
            queueArray[i+1] = input;
            rear++;
            numberOfItems++;
        }

    }
    public static void main(String[] args) {

        TheQueue theQueue = new TheQueue(10);
        theQueue.insertMany("92 64 35 63");
        theQueue.displayTheQueue();
        theQueue.priorityInsert("100");
        theQueue.displayTheQueue();
        theQueue.priorityInsert("75");
        theQueue.displayTheQueue();

    }
}
