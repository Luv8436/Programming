import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        // write your code here
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int paths = findPaths(n );
        System.out.println(paths);
    }
    
    public static int findPaths(int n)
    {
        // allocation space for the arr
       int arr[] = new int[n+1];
       // we will store the paths from ith to 0th step in the ith index of the array
       
       arr[0] = 1;
       for(int i=1;i<=n;i++)
       {
           if(i==1)
           arr[i] = arr[i-1];
           else if(i>=3)
           arr[i] = arr[i-1]+arr[i-2]+arr[i-3];
           else
           arr[i] = arr[i-1]+arr[i-2];
       }
       return arr[n];
    }

}