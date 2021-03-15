// 1. You are given a number n and a number m representing number of rows and columns in a maze.
// 2. You are standing in the top-left corner and have to reach the bottom-right corner. 
// 3. In a single move you are allowed to jump 1 or more steps horizontally (as h1, h2, .. ), or 1 or more steps vertically (as v1, v2, ..) or 1 or more steps diagonally (as d1, d2, ..). 
// 4. Complete the body of getMazePath function - without changing signature - to get the list of all paths that can be used to move from top-left to bottom-right.
// Use sample input and output to take idea about output.

// Note -> The online judge can't force you to write the function recursively but that is what the spirit of question is. Write recursive and not iterative logic. The purpose of the question is to aid learning recursion and not test you.

// Input Format
// A number n
// A number m
// Output Format
// Contents of the arraylist containing paths as shown in sample output
// Constraints
// 0 <= n <= 10
// 0 <= m <= 10
// Sample Input
// 2
// 2
// Sample Output
// [h1v1, v1h1, d1]


import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int m = scn.nextInt();
        ArrayList<String> paths = getMazePaths(0 , 0 , n-1 , m-1);
        System.out.println(paths);

    }

    // sr - source row
    // sc - source column
    // dr - destination row
    // dc - destination column
    public static ArrayList<String> getMazePaths(int sr, int sc, int dr, int dc)     {
        
        ArrayList<String> path = new ArrayList<>();
        
        if(sr==dr && sc==dc )
        {
            path.add("");
            return path;
        }
        
        // horizontal moves
        for(int i=0;i<dc-sc;i++ )
        {
            ArrayList<String> hpaths = getMazePaths(sr , sc+i+1 , dr , dc);
            for(String hpath : hpaths)
            {
                path.add("h"+(i+1)+hpath );
            }
        }
        // vertical moves
        for(int i=0;i<dr-sr;i++ )
        {
            ArrayList<String> vpaths = getMazePaths(sr+i+1 , sc , dr , dc);
            for(String vpath : vpaths)
            {
                path.add("v"+(i+1)+vpath );
            }
        }
        int diagonal;
        if(dr-sr<dc-sc)
        {
            diagonal = dr-sr;
        }
        else
        {
            diagonal = dc-sc;
        }
        // diagonal moves
        for(int i=0;i<diagonal;i++ )
        {
            ArrayList<String> dpaths = getMazePaths(sr+i+1 , sc+i+1 , dr , dc);
            for(String dpath : dpaths)
            {
                path.add("d"+(i+1)+dpath );
            }
        }
        
        return path;
    }
    
}