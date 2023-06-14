import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Vector;

public class Main {
    public static void main(String[] args) {
        int N = 100000;
        Integer array[] = new Integer[N];
        ArrayList list = new ArrayList<Integer>(N);
        LinkedList linkedList = new LinkedList<Integer>();
        Vector vector = new Vector<Integer>(N);

        long startTimeArray, endTimeArray, startTimeList, endTimeList, startTimeLinkedList, endTimeLinkedList,
                startTimeVector, endTimeVector;

        startTimeArray = System.currentTimeMillis();
        // for che inizia da 1 e finisce a 100000 incrementando di 1 che
        for (int i = 0; i < N; i++) {
            array[i] = (int) (Math.random() * Integer.MAX_VALUE);
        }
        endTimeArray = System.currentTimeMillis();

        // calcola il tempo impiegato e inseriscilo nella arraylist
        System.out.println("Tempo di ADD: " + (endTimeArray - startTimeArray));

        // calcola tempo di inserimento in arraylist
        startTimeList = System.currentTimeMillis();
        for (int i = 0; i < N; i++) {
            list.add((int) (Math.random() * Integer.MAX_VALUE));
        }
        endTimeList = System.currentTimeMillis();
        System.out.println("Tempo di ADD: " + (endTimeList - startTimeList) + "ms");


        // calcola tempo di inserimento in linkedlist
        startTimeLinkedList = System.currentTimeMillis();
        for (int i = 0; i < N; i++) {
            linkedList.add((int) (Math.random() * Integer.MAX_VALUE));
        }
        endTimeLinkedList = System.currentTimeMillis();
        System.out.println("Tempo di ADD: " + (endTimeLinkedList - startTimeLinkedList) + "ms");

        // calcola tempo di inserimento in vector
        startTimeVector = System.currentTimeMillis();
        for (int i = 0; i < N; i++) {
            vector.add((int) (Math.random() * Integer.MAX_VALUE));
        }
        endTimeVector = System.currentTimeMillis();
        System.out.println("Tempo di ADD: " + (endTimeVector - startTimeVector) + "ms");

        // calcola tempo di get in array
        int temp;
        startTimeArray = System.currentTimeMillis();
        for (int i = 0; i < N; i++) {
            temp = array[i] + i;
        }
        endTimeArray = System.currentTimeMillis();
        System.out.println("Tempo di GET array: " + (endTimeArray - startTimeArray) + "ms");

        // calcola tempo di get in arraylist
        startTimeList = System.currentTimeMillis();
        for (int i = 0; i < N; i++) {
            temp = (int) list.get(i) + i;
        }
        endTimeList = System.currentTimeMillis();

        System.out.println("Tempo di GET arraylist: " + (endTimeList - startTimeList) + "ms");

        // calcola tempo di get in linkedlist
        startTimeLinkedList = System.currentTimeMillis();
        for (int i = 0; i < N; i++) {
            temp = (int) linkedList.get(i) + i;
        }
        endTimeLinkedList = System.currentTimeMillis();

        System.out.println("Tempo di GET linkedlist: " + (endTimeLinkedList - startTimeLinkedList) + "ms");

        // calcola tempo di get in vector

        startTimeVector = System.currentTimeMillis();

        for (int i = 0; i < N; i++) {
            temp = (int) vector.get(i) + i;
        }
        endTimeVector = System.currentTimeMillis();
        System.out.println("Tempo di GET vector: " + (endTimeVector - startTimeVector) + "ms");


        // calcola tempo di remove in arraylist
        startTimeList = System.currentTimeMillis();
        for (int i = 0; i < N; i++) {
            list.remove(0);
        }
        endTimeList = System.currentTimeMillis();
        System.out.println("Tempo di REMOVE arraylist: " + (endTimeList - startTimeList)+ "ms");

        // calcola tempo di remove in linkedlist
        startTimeLinkedList = System.currentTimeMillis();
        for (int i = 0; i < N; i++) {
            linkedList.remove(0);
        }
        endTimeLinkedList = System.currentTimeMillis();
        System.out.println("Tempo di REMOVE linkedlist: " + (endTimeLinkedList - startTimeLinkedList)+ "ms");

        // calcola tempo di remove in vector
        startTimeVector = System.currentTimeMillis();
        for (int i = 0; i < N; i++) {
            vector.remove(0);
        }
        endTimeVector = System.currentTimeMillis();
        System.out.println("Tempo di REMOVE vector: " + (endTimeVector - startTimeVector)+ "ms");

    }
}
