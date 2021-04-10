// 1. You are given a number n, representing the count of items.
// 2. You are given n numbers, representing the values of n items.
// 3. You are given n numbers, representing the weights of n items.
// 3. You are given a number "cap", which is the capacity of a bag you've.
// 4. You are required to calculate and print the maximum value that can be created in the bag without 
//     overflowing it's capacity.
// Note -> Each item can be taken any number of times. You are allowed to put the same item again 
//                   and again.
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
// 100


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
        
        // create cap+1 size dp array in which ith element indicates the max val when cap=1
        int dp[] = new int[cap+1];
        // value is 0 when cap=0
        dp[0] = 0;
        for(int capacity=1;capacity<=cap;capacity++){
            // select the max val from the weights<cap items
            int max_value = dp[capacity-1];
            for(int w=0;w<n;w++)
            {
                if(weight[w] > capacity ){
                    continue;
                }
                if(val[w]+dp[capacity-weight[w] ]> max_value )
                {
                    max_value = val[w]+dp[capacity-weight[w] ];
                }
            }
            dp[capacity] = max_value;
        }
        System.out.println(dp[cap]);
    }
}