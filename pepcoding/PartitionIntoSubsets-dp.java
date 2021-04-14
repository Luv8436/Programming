// 1. You are given a number n, representing the number of elements.
// 2. You are given a number k, representing the number of subsets.
// 3. You are required to print the number of ways in which these elements can be partitioned in k non-empty subsets.
// E.g.
// For n = 4 and k = 3 total ways is 6
// 12-3-4
// 1-23-4
// 13-2-4
// 14-2-3
// 1-24-3
// 1-2-34
// Input Format
// A number n
// A number k
// Output Format
// A number representing the number of ways in which these elements can be partitioned in k non-empty subsets.
// Constraints
// 0 <= n <= 20
// 0 <= k <= n
// Sample Input
// 4
// 3
// Sample Output
// 6

import java.io.*;
import java.util.*;

public class Main {

   public static void main(String[] args) throws Exception {
       Scanner scn = new Scanner(System.in);
       int n = scn.nextInt();
       int k = scn.nextInt();
       
       // formula f(n,k) = k*f(n-1 , k) + f(n-1 , k-1)
       // create 2d dp array 
       long dp[][] = new long[k+1][n+1];
       for(int subset=0;subset<=k;subset++){
           for(int friend=0;friend<=n;friend++){
               if(subset==0||friend==0){
                   dp[subset][friend]=0;
               }
               else if(subset==1){
                   dp[subset][friend]=1;
               }
               else if(subset>friend){
                   dp[subset][friend]=0;
               }
               else if(subset==friend){
                   dp[subset][friend]=1;
               }
               else
               dp[subset][friend] = subset*dp[subset][friend-1]+dp[subset-1][friend-1];
           }
       }
       
       System.out.println(dp[k][n] );
   }
}