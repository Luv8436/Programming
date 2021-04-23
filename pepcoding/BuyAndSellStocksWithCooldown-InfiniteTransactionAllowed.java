1. You are given a number n, representing the number of days.
2. You are given n numbers, where ith number represents price of stock on ith day.
3. You are required to print the maximum profit you can make if you are allowed infinite transactions, but have to cooldown for 1 day after 1 transaction
i.e. you cannot buy on the next day after you sell, you have to cooldown for a day at-least before buying again.
Note - There can be no overlapping transaction. One transaction needs to be closed (a buy followed by a sell) before opening another transaction (another buy).
Input Format
A number n
.. n more elements
Output Format
A number representing the maximum profit you can make if you are allowed infinite transactions with cooldown of 1 day.
Constraints
0 <= n <= 20
0 <= n1, n2, .. <= 10
Sample Input
12
10
15
17
20
16
18
22
20
22
20
23
25
Sample Output
19
import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        // write your code here
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int arr[] = new int[n];
        for(int i=0;i<n;i++){
            arr[i] = scn.nextInt();
        }
        int buy[] = new int[n];
        int sell[] = new int[n];
        int cooldown[] = new int[n];
        for(int i=0;i<n;i++){
            if(i==0){
                buy[i] = arr[i];
            }
            else {
                buy[i] = Integer.min(buy[i-1] ,arr[i]-cooldown[i-1] );
                sell[i] = Integer.max(sell[i-1], arr[i]-buy[i-1] );
                cooldown[i] = Integer.max(cooldown[i-1],sell[i-1] );
            }
            
        }
        System.out.println(sell[n-1]);
    }

}