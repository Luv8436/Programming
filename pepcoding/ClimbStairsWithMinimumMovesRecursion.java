// 1. You are given a number n, representing the number of stairs in a staircase.
// 2. You are on the 0th step and are required to climb to the top.
// 3. You are given n numbers, where ith element's value represents - till how far from the step you 
//      could jump to in a single move.  You can of-course fewer number of steps in the move.
// 4. You are required to print the number of minimum moves in which you can reach the top of 
//      staircase.
// Note -> If there is no path through the staircase print null.
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
// 4



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
        
        int paths = minSteps(arr , 0 );
        System.out.println(paths);
    }
    
    public static int minSteps(int arr[] , int n )
    {
        if(n==arr.length)
        return 0;
        else if(n>arr.length)
        return arr.length;
        
        int min = arr.length ;
        for(int step=1;step<=arr[n];step++ )
        {
            int steps = minSteps(arr , n+step);
            if(steps<min)
            {
                min = steps;
            }
        }
        
        return min+1;
    }

}