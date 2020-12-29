package linkedList;

public class LinkedList {

    private Node head;
    private static int size = 0;

    public LinkedList(){
        head = null;
    }

    public boolean isEmpty(){
        return head == null;
    }

    public int size(){
      /*  int size_ = 0;
        Node tmp = this.head;

        while(tmp != null)
            size++;*/

        return this.size;
    }

    public void add(int x){
        Node newNode = new Node();
        newNode.val = x;
        newNode.next = head;
        head = newNode;
        size++;
    }

    public void display(){
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
            size++;
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
            size++;
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

        size++;
    }

    public void deleteFront(){
        if(this.isEmpty())
            return;
        else{
            //Node tmp = this.head;
            head = head.next;
            size--;
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
            size--;
        }
        else{
            this.deleteFront();
            this.head = null;
            size--;
        }
    }

    public void reverse(){
        Node tmpHead = this.head;
        Node prev = null;

        while(tmpHead != null){
            Node tmp = tmpHead.next;
            tmpHead.next = prev;
            prev = tmpHead;
            tmpHead = tmp;
        }
        this.head = prev;
    }

    public void split(LinkedList emptyList1, LinkedList emptyList2){
        Node tmp = this.head;
        while(tmp != null){
            head = head.next;
            tmp.next = emptyList1.head;
            emptyList1.head = tmp;
            tmp = head;
            if(tmp != null){
                head = head.next;
                tmp.next = emptyList2.head;
                emptyList2.head = tmp;
                tmp = head;
            }
        }
    }

    public void merge(LinkedList sorted1, LinkedList sorted2){
        if(this.isEmpty()){
            this.pushFront(0);
            Node tmp;
            tmp = this.head;

            while(sorted1.head != null && sorted2.head != null){
                if(sorted1.head.val > sorted2.head.val){
                    tmp.next = sorted2.head;
                    sorted2.head = sorted2.head.next;
                }
                else{
                    tmp.next = sorted1.head;
                    sorted1.head = sorted1.head.next;
                }
                tmp = tmp.next;
            }
            while(sorted1.head != null){
                tmp.next = sorted1.head;
                sorted1.head = sorted1.head.next;
                tmp = tmp.next;
            }
            while(sorted2.head != null){
                tmp.next = sorted2.head;
                sorted2.head = sorted2.head.next;
                tmp = tmp.next;
            }
            this.deleteFront();
        }
    }
}
