// 1. You are given a number n, representing the number of houses.
// 2. In the next n rows, you are given 3 space separated numbers representing the cost of painting nth house with red or blue or green color.
// 3. You are required to calculate and print the minimum cost of painting all houses without painting any consecutive house with same color.
// Input Format
// A number n
// n1red n1blue n1green
// n2red n2blue n2green
// .. n number of elements
// Output Format
// A number representing the minimum cost of painting all houses without painting any consecutive house with same color.
// Constraints
// 1 <= n <= 1000
// 0 <= n1red, n1blue, .. <= 1000
// Sample Input
// 4
// 1 5 7
// 5 8 4
// 3 2 9
// 1 2 4
// Sample Output
// 8


import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int arr[][] = new int[3][n];
        for(int house=0;house<n;house++){
            for(int color=0;color<3;color++){
                arr[color][house] = scn.nextInt();
            }
        }
        
        // creating the dp array in which ith row indicates the minimum cost when ith row color must used at jth home
        int dp[][] = new int[3][n];
        
        // min cost = cost when no of homes are 1
        dp[0][0] = arr[0][0];
        dp[1][0] = arr[1][0];
        dp[2][0] = arr[2][0];
        
        for(int home=1;home<n;home++){
            for(int color=0;color<3;color++){
                if(color==0){
                    dp[color][home] = Integer.min(dp[1][home-1] , dp[2][home-1] ) + arr[color][home];
                }
                else if(color==1){
                    dp[color][home] = Integer.min(dp[0][home-1] , dp[2][home-1] ) + arr[color][home];
                }
                else if(color==2){
                    dp[color][home] = Integer.min(dp[1][home-1] , dp[0][home-1] ) + arr[color][home];
                }
            }
        }
        
        System.out.println(Integer.min(Integer.min(dp[0][n-1] , dp[1][n-1] ) , dp[2][n-1] ) );
        // for(int color=0;color<3;color++){
        //     for(int house=0;house<n;house++){
        //         System.out.print(dp[color][house]+ " " );
        //     }
        //     System.out.println();
        // }
    }
}