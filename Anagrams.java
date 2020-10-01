import java.io.*;
import java.lang.reflect.Array;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.Arrays;
import java.util.concurrent.*;
import java.util.regex.*;

public class Anagrams {
    // Complete the sherlockAndAnagrams function below.
    static int sherlockAndAnagrams(String s) {

        int ctr =0;
        char [] substr;
        char [] str= s.toCharArray();
        int l1 = s.length();
        Hashtable<String, Integer> ht = new Hashtable<String, Integer>();

        for(int i =1; i<l1; i++)
        {
            for(int j =0;j<l1-i+1; j++)
            {
                String val = "";
                int a = i+j-1;
                for(int k =j; k<=a; k++)
                { val += str[k]; }

                if(val.length()>1)
                {
                    substr = val.toCharArray();
                    Arrays.sort(substr);
                    val = new String(substr);
                }


                Boolean value = ht.containsKey(val);
                int newVal = (value == false) ? 1 : (ht.get(val) + 1);
                ht.put(val, newVal);
            }
        }

        Enumeration e = ht.elements();
        while (e.hasMoreElements())
             {
                    int n =(int) e.nextElement();
                    if(n>1) {ctr += n * (n - 1) / 2; }
             }

        return ctr;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args)  {
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");
        String s = scanner.nextLine();
        scanner.close();
        int result = sherlockAndAnagrams(s);

    }
}





















//        System.out.println("Length of string "+l1);
//                for(int i=0; i<l1-1; i++){
//        for(int j = i+1; j<l1; j++){
//
//        System.out.println("Value of i "+i);
//        System.out.println("Value of j "+j);
//
//        if(str[i]==str[j]) {
//        System.out.println("Strings are equal");
//        //Check for palindrome
//        if (j - i == 1) {
//        ctr += 1;
//        System.out.println("Value of ctr " + ctr);
//        } else{
//        String checkstring = (s.substring(i, j + 1));
//
//        checkstr = checkstring.toCharArray();
//
//        //Checking for palindrome
//        int l2 = checkstr.length;
//        for (int u = 0, v = l2 - 1; u < l2 / 2 && v >= l2 / 2; u++, v--) {
//        System.out.println("Value of u " + u);
//        System.out.println("Value of v " + v);
//
//        if (checkstr[u] != checkstr[v]) {
//        System.out.println("Value at u " + checkstr[u]);
//        System.out.println("Value at v " + checkstr[v]);
//        flag = false;
//        }
//
//        }
//        //Palindrome checking ends
//
//        System.out.println("Value of flag " + flag);
//        if (flag) {
//        ctr += l2 - 1;
//        System.out.println("Value of ctr " + ctr);
//        } else {
//        ctr += 2;
//        System.out.println("Value of ctr " + ctr);
//        }
//        }
//        }
//        }
//        }
//
//        //Match for substring
//        System.out.println(ctr);
//
//



