public class Main{

  static int pass = 0;
  static int fail = 0;

  static void test_int (String name, int actual, int expected){
    if (actual == expected) {
      pass++;
      System.out.println(name + " PASS");
    } else {
      fail++;
      System.out.println(name + " FAIL: '" + actual + "' instead of '" + expected + "'");
    }
  }

  static void test_bool (String name, boolean actual, boolean expected){
    if (actual == expected) {
      pass++;
      System.out.println(name + " PASS");
    } else {
      fail++;
      System.out.println(name + " FAIL: '" + actual + "' instead of '" + expected + "'");
    }
  }

  public static void main(String[] args){
    Fifo s1 = new Fifo(16);
    Lifo s2 = new Lifo(16);

    test_bool("Fifo empty 1", s1.isEmpty(), true);
    test_bool("Lifo empty 1", s2.isEmpty(), true);


    for (int i = 0; i<24; i++) {
      s1.add(i);
      s2.add(i);
    }


    test_bool("Fifo full 2", s1.isFull(), true);
    test_bool("Lifo full 2", s2.isFull(), true);

    test_int("Fifo get 1", s1.get(0),16);
    test_int("Lifo get 1", s2.get(0),16);

    test_int("Fifo get 2", s1.get(8),8);
    test_int("Lifo get 2", s2.get(8),8);

    test_int("Fifo remove 1", s1.remove(),8);
    test_int("Lifo remove 2", s2.remove(),23);

    s1.reset();
    s2.reset();


    for (int i = 0; i<124; i++) {
      s1.add(i);
      s2.add(i);
      if (i%3 == 0){
        s1.remove();
        s2.remove();
      }
    }

    test_int("Fifo", s1.remove(),109);
    test_int("Lifo", s2.remove(),122);

    System.out.println("Pass: "+ pass + ", Fail: " + fail);

  }
}
