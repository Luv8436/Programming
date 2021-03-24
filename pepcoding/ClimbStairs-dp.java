1. You are given a number n, representing the number of stairs in a staircase.
2. You are on the 0th step and are required to climb to the top.
3. In one move, you are allowed to climb 1, 2 or 3 stairs.
4. You are required to print the number of different paths via which you can climb to the top.
Input Format
A number n
Output Format
A number representing the number of ways to climb the stairs from 0 to top.
Constraints
0 <= n <= 20
Sample Input
4
Sample Output
7

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        // write your code here
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int steps = climbStairs(n , new int[n+1] );
        System.out.println(steps);
    }
    
    public static int climbStairs(int n , int arr[] )
    {
        if(n==1)
        return 1;
        else if(n==2)
        return 2;
        else if(n==3)
        return 4;
        
        if(arr[n]!= 0 )
        {
            return arr[n];
        }
        
        return climbStairs(n-1 , arr)+climbStairs(n-2, arr)+climbStairs(n-3 , arr);
    }

}