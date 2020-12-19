package linkedList;

public class LinkedList {
    private Node head;

    public LinkedList(){
        head = null;
    }

    public boolean isEmpty(){
        return head == null;
    }

    public void add(int x){
        Node newNode = new Node();
        newNode.val = x;
        newNode.next = head;
        head = newNode;
    }

    public void show(){
        Node tmp = head;
        System.out.print("Head->");
        while(tmp != null){
            System.out.print(tmp.val);
            System.out.print("->");
            tmp = tmp.next;
        }
        System.out.println("NULL");
    }

}
