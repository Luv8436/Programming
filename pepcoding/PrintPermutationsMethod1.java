
// 1. You are given a string str.
// 2. Complete the body of printPermutations function - without changing signature - to calculate and print all permutations of str.
// Use sample input and output to take idea about permutations.

// Note -> The online judge can't force you to write the function recursively but that is what the spirit of question is. Write recursive and not iterative logic. The purpose of the question is to aid learning recursion and not test you.
// Input Format
// A string str
// Output Format
// Permutations of str in order hinted by Sample output
// Constraints
// 0 <= str.length <= 7
// Sample Input
// abc
// Sample Output
// abc
// acb
// bac
// bca
// cab
// cba

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);
        String str = scn.next();
        printPermutations(str , "");
    }

    public static void printPermutations(String str , String permutation) {
        //base case where str is empty
        if(str.length()==0 )
        {
            System.out.println(permutation);
            return;
        }
        
        
        // seperating the first character
        char ch = str.charAt(0);
        String rem = str.substring(1);
        for(int i=permutation.length();i>=0;i-- )
        {
            String s = addCharToString(permutation , ch , i);
            printPermutations(rem , s  );
        }
        
    }
    public static String addCharToString(String str, char c, int pos) {
        StringBuilder stringBuilder = new StringBuilder(str);
        stringBuilder.insert(pos, c);
        return stringBuilder.toString();
    }

}