// 1. You are given a number n and a number m separated by line-break representing the length and breadth of a n * m floor.
// 2. You've an infinite supply of m * 1 tiles.
// 3. You are required to calculate and print the number of ways floor can be tiled using tiles.
// Input Format
// A number n
// A number m
// Output Format
// A number representing the number of ways in which the number of ways floor can be tiled using tiles.
// Constraints
// 1 <= n <= 100
// 1 <= m <= 50
// Sample Input
// 39
// 16
// Sample Output
// 61

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int m = scn.nextInt();
        
        // create the n length dp array in which ith element denotes the number of ways of tiling m*i floor
        int dp[] = new int[n+1];
        
        for(int length=1;length<=n;length++){
            if(length<m){
                dp[length] = 1;
            }
            else if(length==m){
                dp[length] = 2;
            }
            else{
                dp[length] = dp[length-1] + dp[length-m];
            }
        }
        
        System.out.println(dp[n] );
    }
}