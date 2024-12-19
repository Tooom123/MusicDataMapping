public class Fifo extends Storage {

  public Fifo(int size){
    super(size);
  }

  @Override
public int remove() {
    if (isEmpty()) {
        return -1;
    }
    int oldest = memory[(memory.length - nb + write) % memory.length];
    memory[(memory.length - nb + write) % memory.length] = -1;
    nb--;
    return oldest;
}
}

