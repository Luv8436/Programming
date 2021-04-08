// 1. You are given a number n, representing the count of elements.
// 2. You are given n numbers.
// 3. You are given a number "tar".
// 4. You are required to calculate and print true or false, if there is a subset the elements of which add 
//      up to "tar" or not.
// Input Format
// A number n
// n1
// n2
// .. n number of elements
// A number tar
// Output Format
// true or false as required

// Constraints
// 1 <= n <= 30
// 0 <= n1, n2, .. n elements <= 20
// 0 <= tar <= 50
// Sample Input
// 5
// 4
// 2
// 7
// 1
// 3
// 10
// Sample Output
// true


import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int arr[] = new int[n];
        for(int i=0;i<n;i++)
        {
            arr[i] = scn.nextInt();
        }
        
        int tar = scn.nextInt();
        
        // declare the dp array on which element at i , j indicates the boolean value 
        // whether or not the ith row element and above can make the sum equal to jth element column
        
        boolean dp[][] = new boolean[n+1][tar+1];
        
        int flag = 0;
        
        // start filling the dp arr
        for(int row=0;row<n+1;row++)
        {
            for(int col=0;col<tar+1;col++)
            {
                if(row==0)
                {
                    if(col==0)
                    dp[row][col] = true;
                    else
                    dp[row][col] = false;
                }
                else
                {
                    // when the ith row element is not selected and tar is achieved by its previous elements
                    if(dp[row-1][col]==true ){
                        dp[row][col]=true;
                    }
                    else if(col-arr[row-1]>=0 ){
                        // rem tar
                        int rem = col-arr[row-1];
                        if(dp[row-1][rem]==true ){
                            dp[row][col] = true;
                        }
                    }
                    else{
                        dp[row][col] = false;
                    }
                }
                
            }
            if(dp[row][tar]==true )
            {
                flag=1;
                System.out.println("true");
                break;
            }
        }
        if(dp[n][tar]==false && flag==0)
        {
            System.out.println("false");
        }
        
    }
}