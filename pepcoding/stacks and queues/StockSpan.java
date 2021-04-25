// 1. You are given a number n, representing the size of array a.
// 2. You are given n numbers, representing the prices of a share on n days.
// 3. You are required to find the stock span for n days.
// 4. Stock span is defined as the number of days passed between the current day and the first day before today when price was higher than today.

// e.g.
// for the array [2 5 9 3 1 12 6 8 7]
// span for 2 is 1
// span for 5 is 2
// span for 9 is 3
// span for 3 is 1
// span for 1 is 1
// span for 12 is 6
// span for 6 is 1
// span for 8 is 2
// span for 7 is 1
// Input Format
// Input is managed for you
// Output Format
// Output is managed for you
// Constraints
// 0 <= n < 10^5
// -10^9 <= a[i] <= 10^9
// Sample Input

import java.io.*;
import java.util.*;

public class Main{
  public static void display(int[] a){
    StringBuilder sb = new StringBuilder();

    for(int val: a){
      sb.append(val + "
");
    }
    System.out.println(sb);
  }

public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int n = Integer.parseInt(br.readLine());
    int[] a = new int[n];
    for(int i = 0; i < n; i++){
       a[i] = Integer.parseInt(br.readLine());
    }

    int[] span = solve(a);
    display(span);
 }

 public static int[] solve(int[] arr){
   // solve
   int ans[] = new int[arr.length];
   Stack<Integer> e = new Stack<>();
   Stack<Integer> index = new Stack<>();
   ans[0] = 1;
   index.push(0);
   for(int i=1;i<arr.length;i++){
       if(arr[index.peek()]<arr[i] ){
           int flag = 0;
           while(arr[index.peek()]<arr[i] ){
               int j = index.pop();
               if(index.size()==0 ){
                   ans[i] = i+1;
                   index.push(i);
                   flag = 1;
                   break;
               }
           }
           if(flag==0){
               ans[i] = i - index.peek();
               index.push(i);
           }
       }
       else{
            ans[i] = 1;
            index.push(i);
       }
    //   System.out.println(i+" : "+ans[i]);
   }
   return ans;
 }

}