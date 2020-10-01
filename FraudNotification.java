import java.io.*;
import java.util.*;
import java.util.concurrent.atomic.AtomicInteger;

public class FraudNotification {

    // Complete the activityNotifications function below.
    static int activityNotifications(int[] expenditure, int d) {
        int len = expenditure.length;// 9
        int start = (len-d);// d=5, start =4
        int count;
        count=0;
        int j;
        HashMap<Integer, Integer> ht = new HashMap<Integer, Integer>();

        for(int i=0; i<start; i++)
        {   float mid=0;
            float sum=0;

            if(i==0)
            {
                for( j =0; j<d; j++)
                {
                    ht.put(expenditure[j], ht.getOrDefault(expenditure[j], 0)+1);
                }

            }
            else
            {
                int val =ht.get(expenditure[i-1])-1;
                if(val==0)
                {
                    ht.remove(expenditure[i-1]);
                }
                else
                {
                    ht.put(expenditure[i-1], val);
                }

                ht.put(expenditure[i+d-1], ht.getOrDefault(expenditure[i+d-1], 0)+1);

            }

            Set<Integer> values = ht.keySet();
            if(d%2==0)
            {
                int flag =2;
                for(int val: values)
                {
                    sum+= ht.get(val);

                    if(sum>=(float)d/2 && flag>0)
                    {
                        if(sum>(float)d/2 && flag==2)
                        {
                            mid+= 2* val;
                            flag=0;
                        }
                        else if(sum> (float)d/2&& flag==1 )
                        {
                            mid+= val;
                            flag--;
                        }
                        else  if((sum== (float)d/2))
                        {
                            mid+= val;
                            flag--;
                        }
                    }
                    if(flag==0)
                    {
                        break;
                    }

                }

                mid = mid/2;
            }
            else
            {
                for(int val: values)
                {

                    sum+= ht.get(val);

                    if(sum>= (float)d/2)
                    {
                        mid = val;

                        break;
                    }
                }

            }


            if(expenditure[i+d]>= 2*mid){
                count++;

            }
        }



    return count;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
      //  BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));
       // FileReader fr = new FileReader("input.txt");
        BufferedReader bufferedReader = new BufferedReader(new FileReader("input.txt"));

        String[] nd = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nd[0]);

        int d = Integer.parseInt(nd[1]);

        int[] expenditure = new int[n];


        String[] expenditureItems = bufferedReader.readLine().split(" ");
      //  String[] expenditureItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int expenditureItem = Integer.parseInt(expenditureItems[i]);
            expenditure[i] = expenditureItem;
        }

        int result = activityNotifications(expenditure, d);
        System.out.println("Result: "+result);

//        bufferedWriter.write(String.valueOf(result));
//        bufferedWriter.newLine();
//
//        bufferedWriter.close();

        scanner.close();
    }
}
