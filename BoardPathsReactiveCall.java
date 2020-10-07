/*the problem statement is like, we have board of length n, and a dice whose faces numbered from 1 to 6.
initailly we are at starting point of board.
so we have to find the no of ways to reach destn.
for ex. n=3 path will be like-
111,12,21,3
*/
public class BoardPathsReactiveCall {
public static void main(String[] args) {
   path(0,5,"");
   
}
   public static void path(int curr,int end,String ans){
   if(curr==end){
       System.out.println(ans);
       return;
   }
   if(curr>end){        //negative call
       return;
   }
       
       for(int i=1;i<=6;i++){
       path(curr+i,end,ans+i);
   }    
   } 
}
