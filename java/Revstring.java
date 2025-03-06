import java.io.*;
import java.util.*;

public class Revstring {

public static void main(String[]args)
{
    String string;
    System.out.println("Enter the string");
    Scanner sc = new Scanner(System.in);
    string=sc.nextLine();
    String rev="";
    for(int i=string.length()-1;i>=0;i--)
    {
        rev=rev+string.charAt(i);
    }
    System.out.println("oringinal string = " +string);
    System.out.println("Reverse of the string = " +rev);
}
}