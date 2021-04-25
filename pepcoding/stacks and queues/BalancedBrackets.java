// 1. You are given a string exp representing an expression.
// 2. You are required to check if the expression is balanced i.e. closing brackets and opening brackets match up well.

// e.g.
// [(a + b) + {(c + d) * (e / f)}] -> true
// [(a + b) + {(c + d) * (e / f)]} -> false
// [(a + b) + {(c + d) * (e / f)} -> false
// ([(a + b) + {(c + d) * (e / f)}] -> false
// Input Format
// A string str
// Output Format
// true or false

// Constraints
// 0 <= str.length <= 100
// Sample Input
// [(a + b) + {(c + d) * (e / f)}]
// Sample Output
// true

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);
        String s = scn.nextLine();
        Stack<Character> stack = new Stack<>();
        for(int i=0;i<s.length();i++ ){
            if(s.charAt(i)=='['||s.charAt(i)=='{'||s.charAt(i)=='('){
                stack.push(s.charAt(i) );
            }
            else if(s.charAt(i)==']'||s.charAt(i)=='}'||s.charAt(i)==')'){
                if(stack.size()==0){
                    System.out.println("false");
                    return;
                }
                if(s.charAt(i)==']'){
                    if(stack.peek()!='[' ){
                        System.out.println("false");
                        return;
                    }
                }
                else if(s.charAt(i)=='}'){
                    if(stack.peek()!='{' ){
                        System.out.println("false");
                        return;
                    }
                }
                else if(s.charAt(i)==')'){
                    if(stack.peek()!='(' ){
                        System.out.println("false");
                        return;
                    }
                }
                char ch = stack.pop();
            }
        }
        if(stack.size()!=0 ){
            System.out.println("false");
        }else{
        System.out.println("true");
        }
    }

}