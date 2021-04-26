// 1. You are given a number n, representing the size of array a.
// 2. You are given n numbers, representing the elements of array a.
// 3. You are given a number k, representing the size of window.
// 4. You are required to find and print the maximum element in every window of size k.

// e.g.
// for the array [2 9 3 8 1 7 12 6 14 4 32 0 7 19 8 12 6] and k = 4, the answer is [9 9 8 12 12 14 14 32 32 32 32 19 19 19]
// Input Format
// Input is managed for you
// Output Format
// Maximum of each window in separate line
// Constraints
// 0 <= n < 100000
// -10^9 <= a[i] <= 10^9
// 0 < k < n

import java.io.*;
import java.util.*;

public class Main{
  

public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int n = Integer.parseInt(br.readLine());
    int[] a = new int[n];
    for(int i = 0; i < n; i++){
       a[i] = Integer.parseInt(br.readLine());
    }
    int k = Integer.parseInt(br.readLine());

    // code
    // finding the max element on right
    int maxRight[] = findMaxRight(a);
    int i , j=0;
    int ans[] = new int[n-k+1];
    for(i=0;i<n-k+1;i++){
        if(j<i){
            j=i;
        }
        while(maxRight[j]>=i && maxRight[j]<=i+k-1 ){
            j = maxRight[j];
        }
        ans[i] = a[j];
    }
    for(i=0;i<n-k+1;i++){
        System.out.println(ans[i]);
    }
 }
 
 public static int[] findMaxRight(int arr[]){
    Stack<Integer> stack = new Stack<>();
    stack.push(arr.length-1);
    int ans[] = new int[arr.length];
    ans[arr.length-1] = arr.length;
    for(int i=arr.length-2;i>=0;i--){
        while(stack.size()>0 && arr[i]>arr[stack.peek()] ){
            stack.pop();
        }
        if(stack.size()==0 ){
            ans[i] = arr.length;
        }
        else{
            ans[i] = stack.peek();
        }
        stack.push(i);
    }
    return ans;
 }
 
}