import linkedList.LinkedList;

public class Main {

    public static void main(String[] args) {

        LinkedList ll = new LinkedList();
        ll.add(5);
        ll.add(10);
        ll.pushFront(12);
        ll.pushBack(16);
        ll.show();
        ll.deleteFront();
        ll.show();
        ll.deleteBack();
        ll.show();

        System.out.println(ll.isEmpty());
    }
}
