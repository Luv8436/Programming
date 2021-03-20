// 1. You are given a string str of digits. (will never start with a 0)
// 2. You are required to encode the str as per following rules
//     1 -> a
//     2 -> b
//     3 -> c
//     ..
//     25 -> y
//     26 -> z
// 3. Complete the body of printEncodings function - without changing signature - to calculate and print all encodings of str.
// Use the input-output below to get more understanding on what is required
// 123 -> abc, aw, lc
// 993 -> iic
// 013 -> Invalid input. A string starting with 0 will not be passed.
// 103 -> jc
// 303 -> No output possible. But such a string maybe passed. In this case print nothing.

// Note -> The online judge can't force you to write the function recursively but that is what the spirit of question is. Write recursive and not iterative logic. The purpose of the question is to aid learning recursion and not test you.
// Input Format
// A string str
// Output Format
// Permutations of str in order hinted by Sample output

// Constraints
// 0 <= str.length <= 10
// Sample Input
// 655196

// Sample Output
// feeaif
// feesf

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);
        String s = scn.next();
        printEncodings(s , "");
        
    }

    public static void printEncodings(String str , String ans) {
        
        if( str.length()==0 )
        {
            System.out.println(ans);
            return;
        }
        
        char first = str.charAt(0);
        int first_int = (int)first - 48;
        if(first_int == 0)
        return;
        char first_char = (char)(first_int + 96);
        printEncodings( str.substring(1) , ans + first_char );
        if(str.length()>1 )
        {
            char second = str.charAt(1);
            int second_int = (int)second - 48;
            second_int = first_int *10 + second_int;
            if(second_int >= 1 && second_int <=26 )
            {
                char second_char = (char) (second_int + 96);
                printEncodings( str.substring(2) , ans + second_char );
            }
        }
    }

}