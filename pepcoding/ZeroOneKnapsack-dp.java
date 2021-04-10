// 1. You are given a number n, representing the count of items.
// 2. You are given n numbers, representing the values of n items.
// 3. You are given n numbers, representing the weights of n items.
// 3. You are given a number "cap", which is the capacity of a bag you've.
// 4. You are required to calculate and print the maximum value that can be created in the bag without 
//      overflowing it's capacity.

// Note -> Each item can be taken 0 or 1 number of times. You are not allowed to put the same item 
//                again and again.
// Input Format
// A number n
// v1 v2 .. n number of elements
// w1 w2 .. n number of elements
// A number cap
// Output Format
// A number representing the maximum value that can be created in the bag without overflowing it's capacity

// Constraints
// 1 <= n <= 20
// 0 <= v1, v2, .. n elements <= 50
// 0 < w1, w2, .. n elements <= 10
// 0 < cap <= 10
// Sample Input
// 5
// 15 14 10 45 30
// 2 5 1 3 4
// 7
// Sample Output
// 75

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int val[] = new int[n];
        int weight[] = new int[n];
        for(int i=0;i<n;i++)
        {
            val[i] = scn.nextInt();
        }
        for(int i=0;i<n;i++)
        {
            weight[i] = scn.nextInt();
        }
        int cap = scn.nextInt();
        
        // create 2d dp array in which element at i , j stores the max value where cap is j 
        // and create using elements in ith row and above
        
        int dp[][] = new int[n+1][cap+1];
        for(int row=0;row<n+1;row++)
        {
            for(int col=0;col<cap+1;col++)
            {
                // when there is no item 
                if(row==0){
                    dp[row][col]=0;
                }
                // when the weight is greater than capacity then max val is same as prev row max val
                else if(weight[row-1]>col ){
                    dp[row][col] = dp[row-1][col];
                }
                else{
                    dp[row][col] = Integer.max(dp[row-1][col] , val[row-1]+dp[row-1][col-weight[row-1] ] );
                }
            }
        }
        System.out.println(dp[n][cap] );
        
    }
}