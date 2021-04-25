public class SortingAlgo {
    private int[] theArray = new int[50];
    private int arraySize = 10;
    public void generateRandomArray(){
        for (int i = 0; i < arraySize; i++) {
            theArray[i] = (int)(Math.random()*10)+10;
        }
    }
    public void printHorzArray(int i, int j){

        for(int n = 0; n < 51; n++)System.out.print("-");

        System.out.println();

        for(int n = 0; n < arraySize; n++){

            System.out.print("| " + n + "  ");
        }

        System.out.println("|");

        for(int n = 0; n < 51; n++)System.out.print("-");

        System.out.println();

        for(int n = 0; n < arraySize; n++){

            System.out.print("| " + theArray[n] + " ");

        }

        System.out.println("|");

        for(int n = 0; n < 51; n++)System.out.print("-");

        System.out.println();
        if(j != -1){
            // ADD THE +2 TO FIX SPACING
            for(int k = 0; k < ((j*5)+2); k++)System.out.print(" ");
            System.out.print(j);
        }
        // THEN ADD THIS CODE
        if(i != -1){
            // ADD THE -1 TO FIX SPACING
            for(int l = 0; l < (5*(i - j)-1); l++)System.out.print(" ");
            System.out.print(i);
        }
        System.out.println();
    }
    public String linearSearcForValue(int value){
        boolean valueInArray = false;
        String returnMessage = "";
        for (int i = 0; i <arraySize ; i++) {
            if (theArray[i] == value){
                valueInArray = true;
                returnMessage +=   i +" ";
            }
            printHorzArray(i,-1);
        }
        if (!valueInArray){
            returnMessage+=  "none ";
        }
        return "The value was found in the following indexes " +  returnMessage + ".";
    }
    public void swapValues(int indexOne,int indexTwo){
        int temp = theArray[indexOne];
        theArray[indexOne] = theArray[indexTwo];
        theArray[indexTwo] = temp;
    }
    public void bubbleSort(){
        for (int i =arraySize-1 ;i>1; i--) {
            for (int j =0; j <i ; j++) {
                if (theArray[j]>theArray[j+1]) {
                    swapValues(j+1,j);
                    printHorzArray(i,j);
                }
                printHorzArray(i,j);
            }
        }
    }
    public void selectionSort(){
        for (int i = 0; i <arraySize ; i++) {
            int min = i;
            for (int j = i; j <arraySize ; j++) {
                if (theArray[min]> theArray[j])
                    min = j;
            }
             swapValues(min,i);
            printHorzArray(i,-1);
        }
    }
    public void inseritonSort(){
        for (int i = 1; i <arraySize ; i++) {
            int j = i;
            int toInsert = theArray[i];
            while (j>0 && theArray[j-1]> toInsert){
                theArray[j] = theArray[j-1];
                j--;
                printHorzArray(i,j);
            }
            theArray[j] = toInsert;
            printHorzArray(i,j);
            System.out.println("\ntheArray[i] = " + theArray[i]+" theArray[j] = " + theArray[j] + " toInsert = " + toInsert);
        }
    }
    public void binarySearchForValue(int value){
        int lowIndex = 0,highIndex =arraySize;
        while(lowIndex<=highIndex){
            int middleIndex = (lowIndex+highIndex)/2;
            if(theArray[middleIndex]<value) lowIndex = middleIndex+1;
            else if (theArray[middleIndex]>value) highIndex = middleIndex-1;
            else {
                System.out.println("\n Found a match for " + value + " at index "+ middleIndex);
                lowIndex = highIndex +1;
            }
            printHorzArray(middleIndex,-1);
        }


    }

    public static void main(String[] args) {
        SortingAlgo newArr = new SortingAlgo();
        newArr.generateRandomArray();
        //newArr.printHorzArray(-1,-1);
        //System.out.println(newArr.linearSearcForValue(12));
        //newArr.bubbleSort();
        newArr.inseritonSort();
        newArr.binarySearchForValue(11);

    }
}
