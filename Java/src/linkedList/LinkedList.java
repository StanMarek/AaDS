package linkedList;

public class LinkedList {

    private Node head;

    public LinkedList(){
        head = null;
    }

    public boolean isEmpty(){
        return head == null;
    }

    public int size(){
        int size = 0;
        Node tmp = this.head;

        while(tmp != null)
            size++;
        return size;
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

    public void pushFront(int x){
        this.add(x);
    }

    public void pushBack(int x){
        if(this.isEmpty()){
            pushFront(x);
        }
        else{
            Node newNode = new Node();
            newNode.val = x;
            newNode.next = null;
            Node tmp = this.head;
            while(tmp.next != null){
                tmp = tmp.next;
            }
            tmp.next = newNode;
        }
    }

    public void pushAfter(Node nodeBefore, int x){
        if(this.isEmpty() || nodeBefore == null)
            return;

        else{
            Node newNode = new Node();
            newNode.val = x;
            newNode.next = nodeBefore.next;
            nodeBefore.next = newNode;
        }
    }

    public void pushBefore(Node nodeAfter, int x){
        Node newNode = new Node();
        newNode.val = x;
        newNode.next = nodeAfter;

        Node tmp = this.head;
        while(tmp.next != nodeAfter)
            tmp = tmp.next;

        tmp.next = newNode;
    }

    public void deleteFront(){
        if(this.isEmpty())
            return;
        else{
            //Node tmp = this.head;
            head = head.next;
        }
    }

    public void deleteBack(){
        if(this.isEmpty())
            return;
        else if(this.head != null) {
            Node tmp = this.head;

            while(tmp.next.next != null)
                tmp = tmp.next;

            tmp.next = null;
        }
        else{
            this.deleteFront();
            this.head = null;
        }
    }
}
