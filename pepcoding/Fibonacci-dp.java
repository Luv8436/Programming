1. You are given a number n.
2. You are required to print the nth element of fibonnaci sequence.

Note -> Notice precisely how we have defined the fibonnaci sequence
0th element -> 0
1st element -> 1
2nd element -> 1
3rd element -> 2
4th element -> 3
5th element -> 5
6th element -> 8
Input Format
A number n
Output Format
A number representing the nth element of fibonnaci sequence
Constraints
0 <= n <= 45
Sample Input
10
Sample Output
55
import java.io.*;
import java.util.*;

public class Main{

public static void main(String[] args) throws Exception {
    // write your code here
    Scanner scn = new Scanner(System.in);
    int n = scn.nextInt();
    int ans = fibonacci(n , new int[n+1]);
    System.out.println(ans);
 }

public static int fibonacci(int n , int arr[] )
{
    if(n==0)
    return 0;
    else if(n==1)
    return 1;
    
    if(arr[n]!=0 )
    {
        return arr[n];
    }
    
    return fibonacci(n-1 , arr) + fibonacci(n-2 , arr);
}
}