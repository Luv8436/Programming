// 1. You are given a number n, representing the count of coins.
// 2. You are given n numbers, representing the denominations of n coins.
// 3. You are given a number "amt".
// 4. You are required to calculate and print the number of permutations of the n coins using which the 
//      amount "amt" can be paid.

// Note1 -> You have an infinite supply of each coin denomination i.e. same coin denomination can be 
//                   used for many installments in payment of "amt"
// Note2 -> You are required to find the count of permutations and not combinations i.e.
//                   2 + 2 + 3 = 7 and 2 + 3 + 2 = 7 and 3 + 2 + 2 = 7 are different permutations of same 
//                   combination. You should treat them as 3 and not 1.
// Input Format
// A number n
// n1
// n2
// .. n number of elements
// A number amt
// Output Format
// A number representing the count of combinations of coins which can be used to pay the amount "amt"

// Constraints
// 1 <= n <= 20
// 0 <= n1, n2, .. n elements <= 20
// 0 <= amt <= 30
// Sample Input
// 4
// 2
// 3
// 5
// 6
// 7
// Sample Output
// 5


import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int arr[] = new int[n];
        for(int i=0;i<n;i++)
        {
            arr[i] = scn.nextInt();
        }
        
        int tar = scn.nextInt();
        
        // declare the dp array in which ith element stores the number of ways of paying tar using all digits
        // for the target at once
        // means for tar==1 check the number of ways using all the given digits like 2,3,4 etc.
        int dp[] = new int[tar+1];
        for(int index=0;index<tar+1;index++)
        {
            if(index==0){
                dp[index] = 1;
                continue;
            }
            for(int j=0;j<n;j++)
            {
                int coin = arr[j];
                if(index-coin>=0){
                    dp[index] += dp[index-coin];
                }
            }
        }
        System.out.println(dp[tar] );
    }
}