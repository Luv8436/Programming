// 1. You are given a number n, representing the number of days.
// 2. You are given n numbers, where ith number represents price of stock on ith day.
// 3. You are required to print the maximum profit you can make if you are allowed a single transaction.
// Input Format
// A number n
// .. n more elements
// Output Format
// A number representing the maximum profit you can make if you are allowed a single transaction.
// Sample Input
// 9
// 11
// 6
// 7
// 19
// 4
// 1
// 6
// 18
// 4
// Sample Output
// 17

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        // write your code here
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int arr[] = new int[n];
        for(int i=0;i<n;i++){
            arr[i] = scn.nextInt();
        }
        
        int small = arr[0];
        int profit = 0 ;
        
        for(int i=1;i<n;i++){
            if(arr[i]<small ){
                small = arr[i];
            }
            else{
                int curr_profit = arr[i] - small;
                if(curr_profit>profit){
                    profit = curr_profit;
                }
            }
        }
        System.out.println(profit);
    }

}