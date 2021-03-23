// 1. You are given an array(arr) of integers.
// 2. You have to sort the given array in increasing order using radix sort.
// Input Format
// An Integer n 
// arr1
// arr2..
// n integers
// Output Format
// Check the sample ouput and question video.
// Constraints
// 1 <= N <= 10000
// 0 <= arr[i] <= 10^8
// Sample Input
// 5
// 7 
// 2 
// 4 
// 1 
// 3
// Sample Output
// After sorting on 1 place -> 1 2 3 4 7 
// 1 2 3 4 7 


import java.io.*;
import java.util.*;

public class Main {

  public static void radixSort(int[] arr) {
    // write code here  
    int max = arr[0];
    for(int i=1;i<arr.length;i++)
    {
        if(max<arr[i])
        {
            max = arr[i];
        }
    }
    int exp =1;
    while(exp<max)
    {
        countSort(arr , exp);
        exp *= 10;
    }
    
  }

  public static void countSort(int[] arr , int exp) {
    // write code here
   int frequency[] = new int[10];
   // writing frequency of each element in frequency arr
   for(int i=0;i<arr.length;i++)
   {
       frequency[(arr[i]/exp)%10 ] += 1;
   }
   // making the frequency arr into sum of prefixes
   for(int index=0;index<9;index++)
   {
       frequency[index+1] = frequency[index]+frequency[index+1];
   }
   for(int index=0;index<10;index++)
   {
       frequency[index] -= 1;
   }
   
   // back iterate in the arr to place the sorted elements
   // each time we place the element from the arr reduce the index in the frequency array
   int sorted_arr[] = new int[arr.length];
   for(int index=arr.length-1;index>=0;index--)
   {
       sorted_arr[frequency[arr[index]/exp%10 ] ] = arr[index];
       frequency[arr[index]/exp%10 ] -= 1;
   }
   for(int i=0;i<sorted_arr.length;i++)
   {
       arr[i] = sorted_arr[i];
   }
    System.out.print("After sorting on " + exp + " place -> ");
    print(arr);
  }

  public static void print(int[] arr) {
    for (int i = 0; i < arr.length; i++) {
      System.out.print(arr[i] + " ");
    }
    System.out.println();
  }

  public static void main(String[] args) throws Exception {
    Scanner scn = new Scanner(System.in);
    int n = scn.nextInt();
    int[] arr = new int[n];
    for (int i = 0; i < n; i++) {
      arr[i] = scn.nextInt();
    }
    radixSort(arr);
    print(arr);
  }

}