import jdk.swing.interop.SwingInterOpUtils;
import linkedList.LinkedList;

import java.util.Random;

public class Main {

    private LinkedList ll;
    private LinkedList empty1;
    private LinkedList empty2;
    private LinkedList sortedToMerge1;
    private LinkedList sortedToMerge2;

    public static void main(String[] args) {
        new Main();
    }

    private Main(){
        checkBasics();
        checkSplit();
        checkMerge();
    }

    private void checkBasics(){
        Random rand = new Random();

        ll = new LinkedList();
        for(int i = 0; i < 15; i++)
            ll.pushFront(rand.nextInt(50+1));

        System.out.println("Linked list No.1");
        ll.display();
        ll.reverse();
        ll.deleteBack();
        ll.deleteFront();
        ll.display();
        System.out.println("IS EMPTY: " + ll.isEmpty());
        System.out.println("SIZE: " + ll.size());
    }

    private void checkSplit(){
        System.out.println("SPLIT");
        empty1 = new LinkedList();
        empty2 = new LinkedList();
        empty1.display();
        empty2.display();
        ll.display();
        ll.split(empty1, empty2);
        ll.display();
        empty1.display();
        empty2.display();
    }

    private void checkMerge(){
        System.out.println("MERGE");
        sortedToMerge1 = new LinkedList();
        sortedToMerge2 = new LinkedList();
        int j = 1;
        int k = 2;
        for(int i = 0; i < 10; i++){
            sortedToMerge1.pushBack(j+=2);
            sortedToMerge2.pushBack(k+=2);
        }
        sortedToMerge1.display();
        sortedToMerge2.display();
        ll.merge(sortedToMerge1, sortedToMerge2);
        ll.display();
        sortedToMerge1.display();
        sortedToMerge2.display();
    }
}

