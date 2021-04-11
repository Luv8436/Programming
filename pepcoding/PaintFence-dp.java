// 1. You are given a number n and a number k in separate lines, representing the number of fences and number of colors.
// 2. You are required to calculate and print the number of ways in which the fences could be painted so that not more than two fences have same colors.
// Input Format
// A number n
// A number k
// Output Format
// A number representing the number of ways in which the fences could be painted so that not more than two fences have same colors.
// Constraints
// 1 <= n <= 10
// 1 <= k <= 10
// Sample Input
// 8
// 3
// Sample Output
// 3672

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);
        // fences
        int n = scn.nextInt();
        // colors
        int k = scn.nextInt();
        
        // each color has equal options because of symmetry in problem
        // hence solving the question for one color and multiply it by no of colors
        int arr[] = new int[n];
        arr[0] = 1;
        arr[1] = k;
        for(int fence=2;fence<n;fence++){
            arr[fence] = (k-1)*(arr[fence-1]+arr[fence-2] );
        }
        
        System.out.println(k*arr[n-1] );
    }
}