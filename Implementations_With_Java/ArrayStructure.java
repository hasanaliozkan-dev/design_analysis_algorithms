import javax.print.attribute.standard.MediaSize;

public class ArrayStructure {
    private int[] theArray = new int[50];
    private int arraySize = 10;
    public void generateRandomArray(){
        for (int i = 0; i < arraySize; i++) {
            theArray[i] = (int)(Math.random()*10)+10;
        }
    }
    public void printTheArray(){

        for (int i = 0; i <arraySize ; i++) {
            System.out.println("| " + i+" | " + theArray[i] + " |");
            System.out.println("----------");
        }
        System.out.println();
    }
    public int getValueAtIndex(int index){
        if (index>arraySize){
            return -1;
        }
        return theArray[index];
    }
    public boolean doesArrayContainThisValue(int value){
        boolean valueInAray=false;
        for (int i = 0; i <arraySize ; i++) {
            if (theArray[i] == value)
                valueInAray = true;
        }
        return valueInAray;
    }
    public void deleteIndex(int index){
        for (int i = index; i <arraySize ; i++) {
            theArray[i] = theArray[i+1];
        }
        arraySize--;
    }
    public void insertValue(int value){
        if (arraySize<theArray.length){
            theArray[arraySize++] = value;
        }
    }
    public String linearSearcForValue(int value){
        boolean valueInArray = false;
        String returnMessage = "";
        for (int i = 0; i <arraySize ; i++) {
            if (theArray[i] == value){
                valueInArray = true;
                returnMessage +=   i +" ";
            }
        }
        if (!valueInArray){
            returnMessage+=  "none ";
        }
        return "The value was found in the following indexes " +  returnMessage + ".";
    }


    public static void main(String[] args) {
        ArrayStructure newArray = new ArrayStructure();
        newArray.generateRandomArray();
        newArray.printTheArray();
        System.out.println(newArray.getValueAtIndex(5));
        System.out.println(newArray.doesArrayContainThisValue(10));
        newArray.deleteIndex(5);
        newArray.printTheArray();
        newArray.insertValue(34);
        newArray.printTheArray();
        System.out.println(newArray.linearSearcForValue(10));

    }
}

