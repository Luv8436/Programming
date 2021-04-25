// 1. You are given a number n, representing the size of array a.
// 2. You are given n numbers, representing the height of bars in a bar chart.
// 3. You are required to find and print the area of largest rectangle in the histogram.

// e.g.
// for the array [6 2 5 4 5 1 6] -> 12
// Input Format
// Input is managed for you
// Output Format
// A number representing area of largest rectangle in histogram
// Constraints
// 0 <= n < 20
// 0 <= a[i] <= 10
// Sample Input
// 7
// 6
// 2
// 5
// 4
// 5
// 1
// 6
// Sample Output
// 12

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

    // code
    int max = 0;
    for(int i=0;i<n;i++){
        int sr[] = smallerRight(a);
        int sl[] = smallerLeft(a);
        int area = a[i]*(sr[i] - sl[i] - 1);
        if(area>max){
            max = area;
        }
    }
    
    System.out.println(max);
 }
public static int[] smallerRight(int arr[]){
    int ans[] = new int[arr.length];
    Stack<Integer> stack = new Stack<>();
    stack.push(arr.length-1);
    ans[arr.length-1] = arr.length;
    for(int i=arr.length-2;i>=0;i--){
        while(stack.size()>0 && arr[stack.peek()]>=arr[i] ){
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

public static int[] smallerLeft(int arr[]){
    int ans[] = new int[arr.length];
    Stack<Integer> stack = new Stack<>();
    stack.push(0);
    ans[0] = -1;
    for(int i=1;i<arr.length;i++){
        while(stack.size()>0 && arr[stack.peek()]>=arr[i] ){
            stack.pop();
        }
        if(stack.size()==0 ){
            ans[i] = -1;
        }
        else{
            ans[i] = stack.peek();
        }
        stack.push(i);
    }
    
    return ans;
}

}