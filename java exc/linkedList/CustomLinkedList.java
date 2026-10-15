public class CustomLinkedList<T>{
    private Node<T> head;
    private int size;

    /*Възел от списъка зададен с данните му и референция към следващия възел
    като имаме два конструктора съответно за случаите:
    1) - head при първоначално добавяне + за tail
    2) за вътрешните възли.*/
    private static class Node<T>{
        T data;
        Node<T> pointer;

        Node(T data){
        this.data = data;
        this.pointer = null;  
        }

        Node(T data, Node<T> pointer){
            this.data = data;
            this.pointer = pointer;
        }
    }

    public CustomLinkedList() {
        this.head = null;
        this.size = 0;
    }

    public int getSize(){
        return this.size;
    }

    //Обхожда и принтира всеки възел.
    public void traverse(){
        Node<T> current = this.head;
        while(current != null){
            System.out.print(current.data+" -> ");
            current = current.pointer;
        }
        System.out.println("null");
    }

    //
    public void search(T value){
        if (head == null) { System.out.print("Not found"); return; }
        Node<T> current = this.head;
        int index = 0;
        boolean found = false;
        while(current != null){
            if(java.util.Objects.equals(current.data, value)){
                found = true;
                System.out.print("At: "+index+" ");    
            }
            current = current.pointer;
            index++;
        }
        if(!found){
            System.out.print("Not found");
        }
    }

    public void search(int index){
        if (index < 0 || head == null) {
            throw new ArrayIndexOutOfBoundsException("Index out of bounds.");
        }
        Node<T> current = this.head;
        for(int i=0;i<index;i++){
            current = current.pointer;
            if (current == null){
                throw new ArrayIndexOutOfBoundsException("Index out of bounds.");
            }
        }
        System.out.print(current.data);
    }

    //Добавя накрая на списъка.
    public void addTail(T value){
        if(head == null){
            this.head = new Node<>(value);
        } else {
            Node<T> current = this.head;
            while(current.pointer != null){
                current = current.pointer;
            }
            current.pointer = new Node<>(value);
        }
        size++;
    }

    public void addHead(T value){
        if(head == null){
            this.head = new Node<>(value);
        } else {
        this.head = new Node<>(value,this.head);
        }
        size++;
    }

    //Добавя на зададен индекс
    public void add(T value, int index){
        if(index < 0){
            throw new ArrayIndexOutOfBoundsException("Negative index.");
        } else if(index == 0){
            addHead(value);
            size++;
        } else {
            Node<T> current = head;
            for(int i = 0; i < index - 1; i++){
                if(current == null){
                    throw new ArrayIndexOutOfBoundsException("Index out of bounds.");
                }
                current = current.pointer;
            }
            if(current == null){
                throw new ArrayIndexOutOfBoundsException("Index out of bounds.");
            }
            current.pointer = new Node<>(value, current.pointer);
            size++;
        }
    }

    public void removeTail(){
        if(head == null){
            return;
        } else if(head.pointer == null){
            this.head = null;
            size--;
        } else {
            Node<T> current = this.head;
            while (current.pointer.pointer != null) {
                current = current.pointer;
            }
            current.pointer = null;
            size--;
        }
    }

    public void removeHead(){
        if(head == null){
            return;
        } else {
            this.head = head.pointer;
        }
    }

    public void remove(T value){
        if(this.head == null) { return; }
        if(java.util.Objects.equals(head.data, value)){
            this.head = head.pointer;
            size--;
            return;
        }
        Node<T> current = head;
        while(current.pointer != null){
            if(java.util.Objects.equals(current.pointer.data, value)){
                current.pointer = current.pointer.pointer;
                size--;
                break;
            }
            current = current.pointer;
        }
    }

    public void remove(int index){
        if(this.head == null) { return; }
        if(index < 0) { 
            throw new ArrayIndexOutOfBoundsException("Negative index.");
        } else if(index == 0){
            this.head = head.pointer;
            size--;
            return;
        }
        Node<T> current = head;
        for(int i = 0; i < index - 1; i++){
            if (current == null || current.pointer == null){
                throw new ArrayIndexOutOfBoundsException("Out of bounds."); 
            }
            current = current.pointer;
        }
        if(current == null || current.pointer == null) { 
            throw new ArrayIndexOutOfBoundsException("Out of bounds."); 
        }
        current.pointer = current.pointer.pointer;
        size--;
    }

}