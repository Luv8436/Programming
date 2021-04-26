// 1. You are given a postfix expression.
// 2. You are required to evaluate it and print it's value.
// 3. You are required to convert it to infix and print it.
// 4. You are required to convert it to prefix and print it.

// Note -> Use brackets in infix expression for indicating precedence. Check sample input output for more details.
// Input Format
// Input is managed for you
// Output Format
// value, a number
// infix
// prefix
// Constraints
// 1. Expression is a valid postfix expression
// 2. The only operators used are +, -, *, /
// 3. All operands are single digit numbers.
// Sample Input
// 264*8/+3-
// Sample Output
// 2
// ((2+((6*4)/8))-3)
// -+2/*6483

import java.io.*;
import java.util.*;

public class Main{
  

public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String exp = br.readLine();

    // evaluation of postfix expression
    Stack<Integer> stack = new Stack<>();
    for(int i=0;i<exp.length();i++ ){
        if(exp.charAt(i)=='+'||exp.charAt(i)=='-'||exp.charAt(i)=='*'||exp.charAt(i)=='/' ){
            int a = stack.pop();
            int b = stack.pop();
            stack.push(operation(a , b , exp.charAt(i) ) );
        }else{
            stack.push(exp.charAt(i)-'0' );
        }
    }
    System.out.println(stack.peek() );
    
    // converting into infix expression
    Stack<String> stk = new Stack<>();
    for(int i=0;i<exp.length();i++ ){
        if(exp.charAt(i)=='+'||exp.charAt(i)=='-'||exp.charAt(i)=='*'||exp.charAt(i)=='/' ){
            String a = stk.pop();
            String b = stk.pop();
            stk.push("("+b+exp.charAt(i)+a+")" );
        }else{
            stk.push(Character.toString(exp.charAt(i)));
        }
    }
    System.out.println(stk.peek() );
    
    // converting into prefix expression
    Stack<String> prefix = new Stack<>();
    for(int i=0;i<exp.length();i++ ){
        if(exp.charAt(i)=='+'||exp.charAt(i)=='-'||exp.charAt(i)=='*'||exp.charAt(i)=='/' ){
            String a = prefix.pop();
            String b = prefix.pop();
            prefix.push(exp.charAt(i)+b+a );
        }else{
            prefix.push(Character.toString(exp.charAt(i)));
        }
    }
    System.out.println(prefix.peek() );
    
 }
 public static int operation(int a , int b , char ch){
    if(ch=='+'){
        return a+b;
    }else if(ch=='-'){
        return b-a;
    }else if(ch=='*'){
        return a*b;
    }else if(ch=='/'){
        return b/a;
    }
    return 0;
 }
}