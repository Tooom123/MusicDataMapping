public class Fifo extends Storage {

  public Fifo(int size){
    super(size);
  }

  @Override
  public int remove() {
    if (isEmpty()) {
      return -1;
    }
    int oldest = memory[0];
    for (int i = 0; i < nb - 1; i++) {
      memory[i] = memory[i + 1];
    }
    memory[nb - 1] = -1;
    nb--;
    write = (write - 1 + memory.length) % memory.length;
    return oldest;
  }
}
