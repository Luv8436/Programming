// 1. You are given a string str. The string str will contains numbers only, where each number stands for a key pressed on a mobile phone.
// 2. The following list is the key to characters map
//     0 -> .;
//    1 -> abc
//    2 -> def
//    3 -> ghi
//    4 -> jkl
//    5 -> mno
//    6 -> pqrs
//    7 -> tu
//    8 -> vwx
//    9 -> yz
// 3. Complete the body of printKPC function - without changing signature - to print the list of all words that could be produced by the keys in str.
// Use sample input and output to take idea about output.

// Note -> The online judge can't force you to write the function recursively but that is what the spirit of question is. Write recursive and not iterative logic. The purpose of the question is to aid learning recursion and not test you.     
// Input Format
// A string str
// Output Format
// Words that can be produced by pressed keys indictated by str in order hinted by Sample output
// Constraints
// 0 <= str.length <= 10
// str contains numbers only
// Sample Input
// 78
// Sample Output
// tv
// tw
// tx
// uv
// uw
// ux


import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);
        String str = scn.next();
        printKPC(str , "");
    }

    public static void printKPC(String str , String ans) {
        
        if(str.length()==0 )
        {
            System.out.println(ans);
            return ;
        }
        
        char ch = str.charAt(0);
        String rem = str.substring(1);
        
        if(ch=='0')
        {
            printKPC(rem , ans + '.' );
            printKPC(rem , ans + ';' );
        }
        else if(ch=='1')
        {
            printKPC(rem , ans + 'a' );
            printKPC(rem , ans + 'b' );
            printKPC(rem , ans + 'c');
        }
        else if(ch=='2')
        {
            printKPC(rem , ans + 'd');
            printKPC(rem , ans + 'e' );
            printKPC(rem , ans + 'f' );
        }
        else if(ch=='3')
        {
            printKPC(rem , ans + 'g' );
            printKPC(rem , ans + 'h' );
            printKPC(rem , ans + 'i' );
        }
        else if(ch=='4')
        {
            printKPC(rem , ans +  'j' );
            printKPC(rem , ans + 'k' );
            printKPC(rem , ans + 'l' );
        }
        else if(ch=='5')
        {
            printKPC(rem , ans + 'm' );
            printKPC(rem , ans + 'n' );
            printKPC(rem , ans + 'o' );
        }
        else if(ch=='6')
        {
            printKPC(rem , ans + 'p' );
            printKPC(rem , ans + 'q' );
            printKPC(rem , ans + 'r' );
            printKPC(rem , ans + 's' );
        }
        else if(ch=='7')
        {
            printKPC(rem , ans + 't' );
            printKPC(rem , ans + 'u' );
            
        }
        else if(ch=='8')
        {
            printKPC(rem , ans + 'v' );
            printKPC(rem , ans + 'w' );
            printKPC(rem , ans + 'x' );
        }
        else if(ch=='9')
        {
            printKPC(rem , ans + 'y' );
            printKPC(rem , ans + 'z' );
        }
    }

}