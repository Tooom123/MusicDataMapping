public class Lifo extends Storage {

    public Lifo(int size){
        super(size);
    }

    @Override
    public int remove() {
        if (isEmpty()) {
            return -1;
        }
        int newest = memory[(write - 1 + memory.length) % memory.length];
        memory[(write - 1 + memory.length) % memory.length] = -1;
        nb--;
        write = (write - 1 + memory.length) % memory.length;
        return newest;
    }
}
