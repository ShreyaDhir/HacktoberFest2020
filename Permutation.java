//here is the java implementation to find the permutation of a string 

import java.util.Scanner;
import java.lang.*;


public class Permutation{

    void PrintPer(String s,String out)
    {
        if(s.isEmpty())
        {
            System.out.println(out);
        }
        else{
            for(int i=0;i<s.length();i++)
            {
                PrintPer(s.substring(0, i)+s.substring(i+1,s.length()), out+s.charAt(i));
            }
        }
        
    }
    public static void main(String []args)
    {
        Permutation obj=new Permutation();
        Scanner scf=new Scanner(System.in);
        String s=scf.next();
        String o="";
        obj.PrintPer(s,o);
    }
}
