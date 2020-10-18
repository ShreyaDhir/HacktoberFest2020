//java implementation to find the fabonnaci of a number

import java.util.Scanner;

public class Fabonnaci{
    static int fab(int n)
    {
        if(n==0)
         return 0;
        if(n==1 || n==2)
         return 1;
        
        return fab(n-2)+fab(n-1);
    }
    public static void main(String[] args) {
        int N;
        Scanner scf=new Scanner(System.in);
       
        N=scf.nextInt();
        for(int i=0;i<N;i++)
        System.out.print(fab(i) + " ");
    }
}
