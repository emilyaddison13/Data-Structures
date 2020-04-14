public class myQueue {
    private static class Node{
        private int data;
        private Node next;
        private Node(int data){
            this.data = data;
        }

    }

    private Node head;
    private Node tail;

    public boolean isEmpty(){return head == null;}

    public void enqueue(int data){
        Node node = new Node(data);

        if(tail != null) tail.next = node;
        tail = node;
        if (head == null) head = node;
    }

    public int remove(){
        Node tempNode = head;
        head = head.next;
        return tempNode.data;
    }

    public void dequeue(){
        if(head == null){
            return;
        }

        head = head.next;
    }

    public int Qsize(){
        int size=0;
        Node currNode = head;
        while(currNode!=null){
            size++;
            currNode = currNode.next;
        }
        return size;
    }

    public void displayQueue(){
        if(head == null){
            System.out.println("The queue is empty");
        }else {
            Node currNode = head;

            while (currNode != null) {
                System.out.println(currNode.data);
                currNode = currNode.next;
            }
        }
    }
}
