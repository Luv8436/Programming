// 1. You are given a number n, representing the number of rows.
// 2. You are given a number m, representing the number of columns.
// 3. You are given n*m numbers, representing elements of 2d array a, which represents a maze.
// 4. You are standing in top-left cell and are required to move to bottom-right cell.
// 5. You are allowed to move 1 cell right (h move) or 1 cell down (v move) in 1 motion.
// 6. Each cell has a value that will have to be paid to enter that cell (even for the top-left and bottom- 
//      right cell).
// 7. You are required to traverse through the matrix and print the cost of path which is least costly.

// Constraints
// 1 <= n <= 10^2
// 1 <= m <= 10^2
// 0 <= e1, e2, .. n * m elements <= 1000
// Sample Input
// 6
// 6
// 0 1 4 2 8 2
// 4 3 6 5 0 4
// 1 2 4 1 4 6
// 2 0 7 3 2 2
// 3 1 5 9 2 4
// 2 7 0 8 5 1
// Sample Output
// 23


import java.io.*;
import java.util.*;

public class Main {
    
    // public static int minimum(int a , int b)
    // {
    //     int small = a;
    //     if(a>b)
    //     small = b;
        
    //     return small;
    // }

    public static void main(String[] args) throws Exception {
        // write your code here
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int m = scn.nextInt();
        int arr[][] = new int[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                arr[i][j] = scn.nextInt();
            }
        }
        
        // create dp array which indicates the minimum from the given cell to the destination
        int dp[][] = new int[n][m];
        
        // fill the dp array by comparing the cell with both h and v moves and filling the move which have 
        // minimum cost
        for(int row=n-1;row>=0;row--)
        {
            for(int col=m-1;col>=0;col--)
            {
                if(col==m-1&&row==n-1)
                {
                    dp[row][col] = arr[row][col];
                }
                else if(row==n-1)
                {
                    dp[row][col] = arr[row][col]+dp[row][col+1];
                }
                else if(col==m-1)
                {
                    dp[row][col] = arr[row][col]+dp[row+1][col];
                }
                else
                {
                    dp[row][col] = Math.min(dp[row][col+1] , dp[row+1][col] ) + arr[row][col];
                }
            }
        }
        
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         System.out.print(dp[i][j]+"  " );
        //     }
        //     System.out.println();
        // }
        
        System.out.println(dp[0][0] );
    }

}