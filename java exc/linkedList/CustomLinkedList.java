public class CustomLinkedList<T>{
    private Node<T> head; //Пазим първия възел от директен достъп, за да не изгубим последващите референции
    private int size; //Пазим размера на свързания списък в частна променлива, за да няма директен достъп

    /*Клас Възел, който е важен за работата на класа Свързан Списък - 
    съответно чрез static не го даваме на всеки обект(не е нужен на инстанцците поотделно).
    В класа Node задаваме за едносвързан списък променливите - data (елемент) и pointer(референция към следващия възел).
    Имаме два конструктора съответно за случаите:
    1) - head и tail
    2) за вътрешните възли.*/
    private static class Node<T>{
        T data; // T задава типа на свързания списък и на възлите в диамантените скоби.
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

    //Инициализиране на празен свързан списък без начален възел и нулев размер.
    public CustomLinkedList() {
        this.head = null;
        this.size = 0;
    }

    public int getSize(){
        return this.size;
    }

    //Обхожда и принтира всеки възел.
    public void traverse(){
        //Временна променлива съхраняваща текущия възел като започваме от главата.
        Node<T> current = this.head;
        //Цикълът обхожда като преминаването става чрез промяна на текущия възел по съдържащата се в него референция.
        while(current != null){
            System.out.print(current.data+" -> ");
            current = current.pointer;
        }
        //Край на списъка с null.
        System.out.println("null");
    }

    //Търсим възел по стойност в списъка
    public void search(T value){
        if (head == null) { 
            System.out.print("Empty list."); 
            return; 
        } //Проверка за празен списък
        Node<T> current = this.head;
        int index = 0;
        boolean found = false;
        while(current != null){
            if(java.util.Objects.equals(current.data, value)){
                found = true;
                System.out.println("At: "+index+" ");// Принтираме индексите, на които е намерен елемента.    
            }
            current = current.pointer;
            index++;
        }
        if(!found){
            System.out.print("Not found");
        }
    }

    //Търсим каква стойност има възела на дадения индекс
    public void search(int index){
        if (index < 0 || head == null) {
            throw new ArrayIndexOutOfBoundsException("Index out of bounds.");
        }//Правим изключение при което или е празен списъка, или индексът е невалиден.
        Node<T> current = this.head;
        for(int i=0;i<index;i++){
            current = current.pointer;
            if (current == null){
                throw new ArrayIndexOutOfBoundsException("Index out of bounds.");
            }//Правим изключение при което индексът е извън рамките на списъка.
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

    //Сменя първия възел или го създава
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

    //Премахва последния възел
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

    //Премахва първия възел.
    public void removeHead(){
        if(head == null){
            return;
        } else {
            this.head = head.pointer;
        }
    }

    //Премахва първия възел в списъка, който пасва на условието value.
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

    //Премахва възел на определен индекс.
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