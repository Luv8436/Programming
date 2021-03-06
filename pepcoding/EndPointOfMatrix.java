import java.io.*;
import java.util.*;
import java.lang.*;

public class Main {

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
        
        int row = 0;
        int col = 0;
        
        // direction signs
        // 1 for col increasing
        // 2 for row increasing 
        // 3 for col decreasing 
        // 4 for row decreasing
        int dir= 1;
        
        while( (row>=0 && row<n) && (col>=0 && col < m ) )
        {
        	//System.out.println("The program is inside while loop");
            //Thread.sleep(1000);
            // col is increasing keeping the row constant
            if(dir == 1)
            {
            	//System.out.println("The program is inside if of dir==1");
                for(;col<m;col++)
                {
                    if(arr[row][col] == 1 )
                    {
                        // change the direction
                        dir = 2;
                        row++;
                        break;
                    }
                }
            }
            
            
            // row is increasing 
            else if(dir == 2)
            {
            	//System.out.println("The program is inside if of dir==2");
                for(;row<n;row++ )
                {
                    if(arr[row][col] == 1 )
                    {
                        dir = 3;
                        col--;
                        break;
                    }
                }
            }
            
            
            // col is decreasing
            else if(dir == 3)
            {
            	//System.out.println("The program is inside if of dir==3");
                for(;col>=0;col-- )
                {
                    if(arr[row][col] == 1 )
                    {
                        dir = 4;
                        row--;
                        break;
                    }
                }    
            }
            
            // row is decreasing
            else if(dir == 4)
            {
            	//System.out.println("The program is inside if of dir==4");
                for(;row>=0;row-- )
                {
                    if(arr[row][col] == 1 )
                    {
                        dir = 1;
                        col++;
                        break;
                    }
                }    
            }
            
        }
        
        // printing the final output
        if(row<0)
        row++;
        else if(col<0)
        col++;
        else if(row>=n)
        row--;
        else if(col>=m)
        col--;
        System.out.println(row);
        System.out.println(col);
    }

}
