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
        
        int paths = minSteps(arr , 0 , new int[n+1] );
        System.out.println(paths);
    }
    
    public static int minSteps(int arr[] , int n , int qb[])
    {
        if(n==arr.length)
        return 0;
        else if(n>arr.length)
        return arr.length;
        if(qb[n]!=0)
        {
            return qb[n];
        }
        int min = arr.length ;
        for(int step=1;step<=arr[n];step++ )
        {
            int steps = minSteps(arr , n+step , qb);
            if(steps<min)
            {
                min = steps;
            }
        }
        qb[n] = min+1;
        
        return min+1;
    }

}