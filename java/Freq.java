// Source code is decompiled from a .class file using FernFlower decompiler.
import java.util.Scanner;

public class Freq {
   public Freq() {
   }

   public static void main(String[] var0) {
      Scanner var1 = new Scanner(System.in);
      System.out.println("Enter a string");
      String var2 = var1.nextLine();
      System.out.println("Enter the character");
      char var3 = var1.nextLine().charAt(0);
      int var4 = 0;

      for(int var5 = 0; var5 < var2.length(); ++var5) {
         if (var2.charAt(var5) == var3) {
            ++var4;
         }
      }

      System.out.println("count of occurence of " + var3 + "=" + var4);
   }
}
