// 1. You are given a number n, representing the count of elements.
// 2. You are given n numbers, representing n elements.
// 3. You are required to find the maximum sum of a subsequence with no adjacent elements.
// Input Format
// A number n
// n1
// n2
// .. n number of elements
// Output Format
// A number representing the maximum sum of a subsequence with no adjacent elements.

// Constraints
// 1 <= n <= 1000
// -1000 <= n1, n2, .. n elements <= 1000
// Sample Input
// 6
// 5
// 10
// 10
// 100
// 5
// 6
// Sample Output
// 116

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int arr[] = new int[n];
        for(int i=0;i<n;i++){
            arr[i] = scn.nextInt();
        }
        
        // creating the 2d dp array in which jth col element and first row indicates that jth element is selected in subsequence
        // and the second row indicates jth col not selected in the subsequence
        
        int dp[][] = new int[2][n];
        //base case
        dp[0][0] = arr[0];
        dp[1][0] = 0;
        for(int col=1;col<n;col++){
            dp[0][col] = dp[1][col-1] + arr[col];
            dp[1][col] = Integer.max(dp[0][col-1] , dp[1][col-1] );
        }
        System.out.println(Integer.max(dp[0][n-1] , dp[1][n-1] ) );
    }
}