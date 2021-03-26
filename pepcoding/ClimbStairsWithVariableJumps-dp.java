// 1. You are given a number n, representing the number of stairs in a staircase.
// 2. You are on the 0th step and are required to climb to the top.
// 3. You are given n numbers, where ith element's value represents - till how far from the step you 
//      could jump to in a single move.  
//      You can of course jump fewer number of steps in the move.
// 4. You are required to print the number of different paths via which you can climb to the top.
// Input Format
// A number n
// .. n more elements
// Output Format
// A number representing the number of ways to climb the stairs from 0 to top.
// Constraints
// 0 <= n <= 20
// 0 <= n1, n2, .. <= 20
// Sample Input
// 10
// 3
// 3
// 0
// 2
// 1
// 2
// 4
// 2
// 0
// 0
// Sample Output
// 5

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        // write your code here
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int arr[] = new int[n];
        for(int i=0;i<n;i++)
        {
            arr[i] = scn.nextInt();
        }
        int paths = climbStairs(arr , 0 , new int[arr.length+1] );
        System.out.println(paths);
    }
    
    public static int climbStairs(int arr[] , int curr , int discovered_paths[] )
    {
        if(curr==arr.length)
        return 1;
        else if(curr>arr.length)
        return 0;
        
        if(discovered_paths[curr]!=0 )
        {
            return discovered_paths[curr];
        }
        
        int path = 0;
        for(int move=1;move<=arr[curr];move++ )
        {
            path += climbStairs(arr , curr+move ,discovered_paths );
        }
        discovered_paths[curr] = path;
        return path;
    }

}