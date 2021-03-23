// 1. You are given an array(arr) of integers.
// 2. You have to sort the given array in increasing order using count sort.
// Input Format
// An Integer n 
// arr1
// arr2..
// n integers
// Output Format
// Check the sample ouput and question video.
// Constraints
// 1 <= N <= 10000
// -10^8 <= arr[i] <= 10^8
// Sample Input
// 5
// 7 
// -2 
// 4 
// 1 
// 3
// Sample Output
// -2
// 1
// 3
// 4
// 7

import java.io.*;
import java.util.*;

public class Main { 

  public static void countSort(int[] arr, int min, int max) {
   //write your code here
   int range = max-min+1;
   int frequency[] = new int[range];
   // writing frequency of each element in frequency arr
   for(int i=0;i<arr.length;i++)
   {
       frequency[arr[i] - min] += 1;
   }
   // making the frequency arr into sum of prefixes
   for(int index=0;index<range-1;index++)
   {
       frequency[index+1] = frequency[index]+frequency[index+1];
   }
   for(int index=0;index<range;index++)
   {
       frequency[index] -= 1;
   }
   
   // back iterate in the arr to place the sorted elements
   // each time we place the element from the arr reduce the index in the frequency array
   int sorted_arr[] = new int[arr.length];
   for(int index=arr.length-1;index>=0;index--)
   {
       sorted_arr[frequency[arr[index]-min ] ] = arr[index];
       frequency[arr[index]-min ] -= 1;
   }
   for(int i=0;i<sorted_arr.length;i++)
   {
       arr[i] = sorted_arr[i];
   }
   
  }

  public static void print(int[] arr) {
    for (int i = 0; i < arr.length; i++) {
      System.out.println(arr[i]);
    }
  }

  public static void main(String[] args) throws Exception {
    Scanner scn = new Scanner(System.in);
    int n = scn.nextInt();
    int[] arr = new int[n];
    int max = Integer.MIN_VALUE;
    int min = Integer.MAX_VALUE;
    for (int i = 0; i < n; i++) {
      arr[i] = scn.nextInt();
      max = Math.max(max, arr[i]);
      min = Math.min(min, arr[i]);
    }
    countSort(arr,min,max);
    print(arr);
  }

}