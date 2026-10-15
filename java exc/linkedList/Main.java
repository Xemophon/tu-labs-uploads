class Main{
    public static void main(String[] args) {
        CustomLinkedList<Float> list = new CustomLinkedList<>();
        list.addHead(1.0f);
        list.addTail(3.0f);
        list.addTail(2.0f);
        list.add(1.5f, 2);
        list.remove(1.0f);
        list.addTail(1.43f);
        System.out.println(list.getSize());
        list.remove(2);
        list.removeHead();
        list.search(1.43f);
        list.search(1);

        list.traverse();
    }
}