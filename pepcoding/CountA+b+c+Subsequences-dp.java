// 1. You are given a string str.
// 2. You are required to calculate and print the count of subsequences of the nature a+b+c+.
// For abbc -> there are 3 subsequences. abc, abc, abbc
// For abcabc -> there are 7 subsequences. abc, abc, abbc, aabc, abcc, abc, abc.
// Input Format
// A string str
// Output Format
// count of subsequences of the nature a+b+c+
// Constraints
// 0 < str.length <= 10
// Sample Input
// abcabc
// Sample Output
// 7

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);
        String s = scn.nextLine();
        
        // create the 2d dp array in which row1-a+ , row2-a+b+ , row3-a+b+c+ subsequences of string of length upto col index = i
        int dp[][] = new int[3][s.length()+1 ];
        
        // if s.length()==0
        dp[0][0] = 0;
        dp[1][0] = 0;
        dp[2][0] = 0;
        
        // else
        for(int length=1;length<=s.length();length++ )
        {
            if(s.charAt(length-1)=='a' ){
                // subsequences of a+ = 2(a+) + 1
                dp[0][length] = 2*dp[0][length-1]+1;
                // rest remain unchanged
                dp[1][length] = dp[1][length-1];
                dp[2][length] = dp[2][length-1];
            }
            else if(s.charAt(length-1)=='b'){
                // subsequences of a+b+ = 2(a+b+) + (a+)
                dp[1][length] = 2*dp[1][length-1]+dp[0][length-1];
                // rest remain unchanged
                dp[0][length] = dp[0][length-1];
                dp[2][length] = dp[2][length-1];
            }
            else{
                // subsequences of a+b+c+ = 2(a+b+c+) + (a+b+)
                dp[2][length] = 2*dp[2][length-1]+dp[1][length-1];
                // rest remain unchanged
                dp[0][length] = dp[0][length-1];
                dp[1][length] = dp[1][length-1];
            }
        }
        
        System.out.println(dp[2][s.length() ] );
        
    }
}