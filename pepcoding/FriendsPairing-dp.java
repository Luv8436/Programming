// 1. You are given a number n, representing the number of friends.
// 2. Each friend can stay single or pair up with any of it's friends.
// 3. You are required to print the number of ways in which these friends can stay single or pair up.
// E.g.
// 1 person can stay single or pair up in 1 way.
// 2 people can stay singles or pair up in 2 ways. 12 => 1-2, 12.
// 3 people (123) can stay singles or pair up in 4 ways. 123 => 1-2-3, 12-3, 13-2, 23-1.
// Input Format
// A number n
// Output Format
// A number representing the number of ways in which n friends can stay single or pair up.
// Constraints
// 0 <= n <= 20
// Sample Input
// 4
// Sample Output
// 10

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        // write your code here
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        // create the dp array in which ith col indicates the number of ways to pair n friends
        // think each friend has two options either he remain single and hence find the 
        // number of ways for pairing n-1 friend + he pair with each n-1 friends and 
        // find the number of ways for pairing n-2 friends 
        int dp[] = new int[n+1];
        
        // base case by hand
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1] + (i-1)*dp[i-2];
        }
        

        System.out.println(dp[n] );
    }
    
}