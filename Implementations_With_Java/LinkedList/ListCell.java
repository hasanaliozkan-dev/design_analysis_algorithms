public class ListCell {
    public static void main(String[] args) {
        ListLinked listLinked = new ListLinked();
        listLinked.addDatum(3);
        listLinked.addDatum(4);
        listLinked.addDatum(5);
        listLinked.display();

    }
    int datum;
    ListCell next;
    public ListCell(int datum){
        this.datum = datum;
    }
    public void display(){
        System.out.println("Datum : " + datum);
    }

    @Override
    public String toString() {
        return String.valueOf(datum);
    }

}
class ListLinked{
    ListCell firstCell;
    int length = 0;
    public ListLinked(){
        firstCell = null;
    }
    public boolean isEmpty(){
        while (firstCell.next != null){
            firstCell = firstCell.next;
            length++;
        }
        return false;
    }
    public void addDatum(int datum){
      ListCell currentCell = firstCell;
      ListCell nextCell = firstCell;
      if (currentCell == null){
          currentCell = new ListCell(datum);
          currentCell.next = null;
          nextCell = currentCell;
          currentCell.next = nextCell;
          System.out.println("if");
      }
      else {
          while (currentCell.next!= null){
              currentCell = currentCell.next;
              System.out.println("else-while");
          }
          currentCell = new ListCell(datum);
          currentCell.next = null;
          nextCell = currentCell;
          currentCell.next = nextCell;

      }
    }
    public void display(){
        ListCell tempCell = firstCell;
        while (tempCell!= null){
            tempCell.display();
            System.out.println("Next Cell : " + tempCell.next);
            System.out.println();
        }
    }


}

