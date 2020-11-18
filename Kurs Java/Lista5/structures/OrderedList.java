package structures;

import java.util.Iterator;

public class OrderedList<T extends Comparable<T>> implements OrderedSequence<T>, Iterable<T> {

    private class Node<T extends Comparable<T>> {
        public Node<T> next;
        public T data;

        public Node(T el) {
            next = null;
            data = el;
        }
    }
    private Node<T> start;
    private int length;

    public OrderedList() {
        start = new Node<T>(null);
        length = 0;
    }

    public void insert(T el) {

        if(el == null) throw new NullPointerException();

        Node<T> new_node = new Node<T>(el);
        Node<T> p = start;

        while ((p.next != null) && (p.next.data.compareTo(new_node.data) < 0)) {
            p = p.next;
        }

        if(p.next != null && p.next.data.compareTo(new_node.data) == 0) {
            return;
        }

        new_node.next = p.next;
        p.next = new_node;
        length++;
    }

    public void remove(T el) {

        if(el == null) throw new NullPointerException();

        Node<T> p = start;

        while ((p.next != null) && (p.next.data.compareTo(el) != 0)) {
            p = p.next;
        }

        p.next= p.next.next;
        length--;
    }

    public T min() {
        return start.next.data;
    }
    
    public T max() {
        Node<T> p = start;

        for(int i = 0; i<length; i++) {
            p = p.next;
        }
        return p.data;
    }
    
    public T at(int pos) {
        Node<T> p = start;

        for(int i = 0; i<pos; i++) {
            p = p.next;
        }
        return p.data;
    }

    public boolean search(T el) {

        if(el == null) throw new NullPointerException();

        Node<T> p = start;

        while ((p.next != null) && (p.next.data.compareTo(el) != 0)) {
            p = p.next;
        }

        if(p.next != null) return true;

        return false;
    }
    
    public int index(T el) {

        if(el == null) throw new NullPointerException();

        Node<T> p = start;
        int i = 1;

        while ((p.next != null) && (p.next.data.compareTo(el) != 0)) {
            p = p.next;
            i++;
        }

        if(p.next != null) return i;
        else return 0;
    }

    public void printList() {
        Node<T> temp = start;

        while(temp.next != null){
            System.out.println(temp.next.data);
            temp = temp.next;
        };
    }

    public Iterator<T> iterator() {
        return new MyIterator<T>(start);
    }

    private class MyIterator<T extends Comparable<T>> implements Iterator<T>{
        Node<T> current;

        public MyIterator(Node<T> start) {
            current = start.next;
        }

        public boolean hasNext() {
            return current != null;
        }

        public T next() {
            T elem = current.data;
            current = current.next;
            return elem;
        }

        public void remove() {
            current = current.next;
        }

    }

}