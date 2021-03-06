import java.io.*;
import java.util.*;

public class StateOfWakanda{

public static void main(String[] args) throws Exception {
    // write your code here
    int n , m ;
    Scanner scn = new Scanner(System.in);
    n = scn.nextInt();
    m = scn.nextInt();
    int arr[][] = new int[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            arr[i][j] = scn.nextInt();
        }
    }
    for(int col=0;col<m;col++ )
    {
        if(col%2==0)
        {
            for(int row=0;row<n;row++)
            {
                System.out.println(arr[row][col]);
            }
        }
        else
        {
            for(int row=n-1;row>=0;row--)
            {
                System.out.println(arr[row][col]);
            }
        }
    }
 }

}
