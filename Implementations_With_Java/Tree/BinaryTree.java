import javax.sound.midi.Soundbank;

public class BinaryTree {
    Node root;
    public void addNode(int data,String name){
        Node tempNode = new Node(data,name);
        if(root == null){
            root = tempNode;
        }
        else {
            Node focusNode = root;
            Node parent ;
            while(true){
                parent = focusNode;
                if(data<focusNode.data){
                    focusNode = focusNode.left;
                    if(focusNode == null){
                        parent.left = tempNode;
                        return;
                    }
                }
                else{
                    focusNode = focusNode.right;
                    if(focusNode == null){
                        parent.right = tempNode;
                        return;
                    }
                }

            }

        }

    }
    public void inOrderTraverseTheTree(Node root){
        if(root!= null){
            inOrderTraverseTheTree(root.left);
            System.out.println(root);
            inOrderTraverseTheTree(root.right);
        }
    }
    public void preOrderTraverseTheTree(Node root){
        if(root!= null){

            System.out.println(root);
            preOrderTraverseTheTree(root.left);
            preOrderTraverseTheTree(root.right);
        }
    }
    public void postOrderTraverseTheTree(Node root){
        if(root!= null){
            postOrderTraverseTheTree(root.left);
            postOrderTraverseTheTree(root.right);
            System.out.println(root);

        }
    }
    public Node findNode(int data){
        Node focusNode = root;
        while (focusNode.data!= data){
            if (data<focusNode.data){
                focusNode = focusNode.left;
            }
            else{
                focusNode = focusNode.right;
            }
            if(focusNode == null){
                return null;
            }
        }
        return focusNode;
    }
    public boolean remove(int data){
        Node focusNode = root;
        Node parent = root;
        boolean isItALeft=true;
        while (focusNode.data!=data){
            parent = focusNode;
            if(data<focusNode.data){
                isItALeft = true;
                focusNode = focusNode.left;

            }else {
                isItALeft = false;
                focusNode = focusNode.right;
            }
            if (focusNode == null) return false;
        }
        if (focusNode.left == null && focusNode.right== null){
            if (focusNode ==root){
                root =null;
            }else if (isItALeft){
                parent.left = null;

            }else {
                parent.right =null;
            }
        }else if (focusNode.right ==null){
            if (focusNode == root) root = focusNode.left;
            else  if (isItALeft) parent.left = focusNode.left;
            else parent.right = focusNode.left;

        }else if(focusNode.left == null){
            if (focusNode==root) root = focusNode.right;
            else if (isItALeft) parent.left=focusNode.right;
            else parent.right = focusNode.left;

        }else {
            Node replacement = getReplacementNode(focusNode);
            if (focusNode==root) root =replacement;
            else if (isItALeft) parent.left = replacement;
            else  parent.right =replacement;
            replacement.left = focusNode.left;
        }
        return true;


    }

    public Node getReplacementNode(Node replacedNode) {
        Node replacementParent =replacedNode;
        Node replacement = replacedNode;
        Node focusNode = replacedNode.right;
        while (focusNode!=null){
            replacementParent = replacement;
            replacement = focusNode;
            focusNode = focusNode.left;
        }
        if (replacement != replacedNode.right){
            replacementParent.left = replacement.right;
            replacement.right =replacedNode.right;
        }
        return replacement;

    }


    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
        tree.addNode(50,"Boss");
        tree.addNode(25,"Vice Pres");
        tree.addNode(15,"Office Manager");
        tree.addNode(30,"Secretary");
        tree.addNode(75,"Sales Manager");
        tree.addNode(85,"Salesman 1");
        tree.postOrderTraverseTheTree(tree.root);
        System.out.println();
        System.out.println("Search for 50");
        System.out.println(tree.findNode(850));
        System.out.println();
        System.out.println("remove key 25");
        tree.remove(25);
        tree.postOrderTraverseTheTree(tree.root);
    }


}
class Node{
    int data;
    Node left;
    Node right;
    String name;


    Node(int data,String name){
        this.data = data;
        this.name = name;

    }

    @Override
    public String toString() {
        return name + " has a data " + data;
    }
}
