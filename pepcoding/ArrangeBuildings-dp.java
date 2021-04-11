// 1. You are given a number n, which represents the length of a road. The road has n plots on it's each side.
// 2. The road is to be so planned that there should not be consecutive buildings on either side of the road.
// 3. You are required to find and print the number of ways in which the buildings can be built on both side of roads.
// Input Format
// A number n
// Output Format
// A number representing the number of ways in which the buildings can be built on both side of roads.
// Constraints
// 0 < n <= 45
// Sample Input
// 6
// Sample Output
// 441

import java.io.*;
import java.util.*;

public class Main{

public static void main(String[] args) throws Exception {
    // write your code here
    Scanner scn = new Scanner(System.in);
    int n = scn.nextInt();
    
    // solve the number of ways on one side of the road first
    // then square it to get the final ans because total combinations are nC1 * nC1 = n*n
    
    // create the 2d dp array in which one row represents no of ways ending with B and other ending with S.
    int dp[][] = new int[2][n+1];
    
    // when the length of road is 0 then number of ways of is 0 for both ending with B and ending with S.
    dp[0][0] = 0;
    dp[1][0] = 0;
    // number of ways when length=1 is 1 for both ending with B(B) and S(S)
    if(n>=1){
        dp[0][1] = 1;
        dp[1][1] = 1;
    }
    
    // iterate from the length of road = 0 (col=0) to length of road=n(col=n)
    for(int length=2;length<=n;length++){
        // number of ways for length=2 and ending with B is equal to number of ways of length=1 and ending with S
        // because we append B in end of them to make them length=3 and satisfying the constraints
        
        // number of ways for length=2 and ending with S is equal to number of ways of length=1 & ending with (S+B)
        // because we append S in end of those strings
        
        // ending with S
        dp[0][length] = dp[0][length-1]+dp[1][length-1];
        
        // ending with B
        dp[1][length] = dp[0][length-1];

    }
    
    // total = ending with S and ending with B
    long total = dp[0][n]+dp[1][n];
    
    long ans = total*total;
    System.out.println(ans);
 }

}