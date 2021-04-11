// 1. You are given a number n and a number k separated by a space, representing the number of houses and number of colors.
// 2. In the next n rows, you are given k space separated numbers representing the cost of painting nth house with one of the k colors.
// 3. You are required to calculate and print the minimum cost of painting all houses without painting any consecutive house with same color.
// Input Format
// A number n
// n1-0th n1-1st n1-2nd .. n1-kth
// n2-0th n2-1st n2-2nd .. n2-kth
// .. n number of elements
// Output Format
// A number representing the minimum cost of painting all houses without painting any consecutive house with same color.
// Constraints
// 1 <= n <= 1000
// 1 <= k <= 10
// 0 <= n1-0th, n1-1st, .. <= 1000
// Sample Input
// 4 3
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
        int colors = scn.nextInt();
        int arr[][] = new int[colors][n];
        for(int house=0;house<n;house++){
            for(int color=0;color<colors;color++){
                arr[color][house] = scn.nextInt();
            }
        }
        
        // creating the dp array in which ith row indicates the minimum cost when ith row color must used at jth home
        int dp[][] = new int[colors][n];
        
        // min cost = cost when no of homes are 1
        for(int color=0;color<colors;color++){
            dp[color][0] = arr[color][0];
        }
        
        for(int home=1;home<n;home++){
            for(int color=0;color<colors;color++){
                int min = dp[(color+1)%colors][home-1];
                for(int index= (color+2)%colors ; index!=color;index = (index+1)%colors ){
                    if(min>dp[index][home-1] ){
                        min = dp[index][home-1];
                    }
                }
                
                // put that min into the current dp
                dp[color][home] = min+arr[color][home] ;
            }
        }
        
        int final_min = dp[0][n-1];
        for(int color=1;color<colors;color++){
            if(final_min>dp[color][n-1] ){
                final_min = dp[color][n-1];
            }
        }
        
        System.out.println(final_min );
        // for(int color=0;color<colors;color++){
        //     for(int house=0;house<n;house++){
        //         System.out.print(dp[color][house]+ " " );
        //     }
        //     System.out.println();
        // }
    }
}