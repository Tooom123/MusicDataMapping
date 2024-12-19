import java.util.Arrays;

public abstract class Storage {

  protected int[] memory;
  protected int write;
  protected int nb;

  public Storage(int size){
    memory = new int[size];
    Arrays.fill(memory, -1);
    write = 0;
    nb = 0;
  }

  public boolean isFull(){
    return nb == memory.length;
  }

  public boolean isEmpty() {
    return nb == 0;
  }

  public void add(int i){
    memory[write] = i;
    write = (write + 1) % memory.length;
    if (nb < memory.length) {
      nb++;
    }
  }

  public int get(int i){
    if (i < 0 || i >= nb) {
      return -1;
    }
    return memory[i];
  }

  public void reset(){
    Arrays.fill(memory, -1);
    write = 0;
    nb = 0;
  }

  public abstract int remove();

}
