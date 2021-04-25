public class Link {
    public static void main(String[] args) {
        LinkList newLinkedList = new LinkList();
        newLinkedList.insertFirstLink("hasan",1);
        newLinkedList.insertFirstLink("ali",2);
        newLinkedList.insertFirstLink("ozkan",3);
        newLinkedList.insertFirstLink("hasan",4);
        newLinkedList.insertFirstLink("ali",5);
        newLinkedList.insertFirstLink("ozkan",6);
        newLinkedList.insertFirstLink("hasan",7);
        newLinkedList.insertFirstLink("ali",8);
        newLinkedList.insertFirstLink("ozkan",9);
        newLinkedList.display();


    }
    public String bookName;
    public int millionsSold;
    public Link next;
    public Link(String bookName,int millionsSold) {this.bookName =bookName;this.millionsSold= millionsSold;}
    public void display(){
        System.out.println(bookName +" : "+millionsSold + " 000000");
    }

    @Override
    public String toString() {
        return bookName;
    }
}
class LinkList{
    public Link firstLink;
    public LinkList(){
        firstLink = null;
    }
    public boolean isEmpty(){
        return (firstLink== null);
    }
    public void insertFirstLink(String bookName,int millionsSold){
        Link newLink = new Link(bookName,millionsSold);
        newLink.next = firstLink;
        firstLink = newLink;
    }
    public Link removeFirst(){
        Link linkReference = firstLink;
        if(!isEmpty()){
            firstLink.next = firstLink;
        }else {
            System.out.println("Empty Linked List!!!");
        }
        return linkReference;
    }
    public void  display(){
        Link theLink = firstLink;
        while (theLink!= null){
            theLink.display();
            System.out.println("Next Link : " + theLink.next);
            theLink = theLink.next;
            System.out.println();
        }
    }
    public Link find(String bookName){
        Link theLink = firstLink;
        if (!isEmpty()){
            while (theLink.bookName != bookName){
                if (theLink.next == null )
                    return null;
                else
                    theLink = theLink.next;

            }
        } else {
            System.out.println("Empty LinkList!!!");
        }
        return theLink;
    }
    public Link removeLink (String bookName){
        Link currentLink = firstLink;
        Link previousLink = firstLink;
        while (currentLink.bookName != bookName){
            if (currentLink.next == null)
                return null;
            else {
                previousLink = currentLink;
                currentLink = currentLink.next;
            }

        }
        if (currentLink == firstLink){
            firstLink = firstLink.next;
        }
        else{
            previousLink.next = currentLink.next;
        }

        return currentLink;
    }
}
