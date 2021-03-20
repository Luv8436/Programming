import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int m = scn.nextInt();
        printMazePaths(0 , 0 , n-1 , m-1 , "");
    }

    // sr - source row
    // sc - source column
    // dr - destination row
    // dc - destination column
    public static void printMazePaths(int sr, int sc, int dr, int dc, String psf) {
        
        if(sr==dr && sc==dc)
        {
            System.out.println(psf);
            return;
        }
        // printing the horiontal moves
        for(int h=1;h<=dc-sc;h++)
        {
            String hMove = "h"+h;
            printMazePaths(sr , sc + h , dr , dc , psf+ hMove);
        }
        // printing the vertical moves
        for(int v=1;v<=dr-sr;v++)
        {
            String vMove = "v"+v;
            printMazePaths(sr+v , sc , dr , dc , psf+ vMove);
        }
        int row = dr-sr;
        int col = dc-sc;
        int diagonal ;
        if(row<col)
        diagonal = row;
        else
        diagonal = col;
        // printing the diagonal moves
        for(int d=1;d<=diagonal;d++)
        {
            String dMove = "d"+d;
            printMazePaths(sr+d , sc + d , dr , dc , psf+ dMove);
        }
    }

}