// 1. You are given an infix expression.
// 2. You are required to convert it to postfix and print it.
// 3. You are required to convert it to prefix and print it.
// Input Format
// Input is managed for you
// Output Format
// postfix
// prefix
// Constraints
// 1. Expression is balanced
// 2. The only operators used are +, -, *, /
// 3. Opening and closing brackets - () - are used to impact precedence of operations
// 4. + and - have equal precedence which is less than * and /. * and / also have equal precedence.
// 5. In two operators of equal precedence give preference to the one on left.
// 6. All operands are single digit numbers.
// Sample Input
// a*(b-c+d)/e
// Sample Output
// abc-d+*e/
// /*a+-bcde

import java.io.*;
import java.util.*;

public class Main{
  

public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String exp = br.readLine();

    // code
    postfixEvaluation(exp);
    prefixEvaluation(exp);
 }
 
 public static void prefixEvaluation(String exp){
    Stack<Character> operators = new Stack<>();
    Stack<String> operands = new Stack<>();
    for(int i=0;i<exp.length();i++ ){
        if(exp.charAt(i)=='+'||exp.charAt(i)=='/'||exp.charAt(i)=='*'||exp.charAt(i)=='-' ){
            if(operators.size()==0 || operators.peek()=='(' ){
                operators.push(exp.charAt(i));
                
            }
            else if(precedence(exp.charAt(i) , operators.peek() ) ){
                operators.push(exp.charAt(i));
            }
            else{
                while(operators.size()>0 && operators.peek()!='(' && !precedence(exp.charAt(i) , operators.peek() ) ){
                    Character ch = operators.pop();
                    String s1 = operands.pop();
                    String s2 = operands.pop();
                    String s = ch+s2+s1;
                    // System.out.println("string : "+s);
                    operands.push(s);
                }
               
                operators.push(exp.charAt(i) );
            }
        }
        else if (exp.charAt(i)==')' ){
            
            while(operators.peek()!='(' ){
                String s1 = operands.pop();
                String s2 = operands.pop();
                Character ch = operators.pop();
                String s = ch+s2+s1;
                // System.out.println("string : "+s);
                operands.push(s);
            }
            operators.pop();
        }
        else if (exp.charAt(i)=='(' ){
            operators.push('(');
        }
        else{
            operands.push(Character.toString( exp.charAt(i)) );
        }
    }
    while(operators.size()!=0 ){
        String s1 = operands.pop();
        String s2 = operands.pop();
        Character ch = operators.pop();
        String prefix = ch+s2+s1;
        operands.push(prefix);
    }
    
    System.out.println(operands.pop() );
 }
 
 public static void postfixEvaluation(String exp){
    Stack<Character> operators = new Stack<>();
    Stack<String> operands = new Stack<>();
    for(int i=0;i<exp.length();i++ ){
        if(exp.charAt(i)=='+'||exp.charAt(i)=='/'||exp.charAt(i)=='*'||exp.charAt(i)=='-' ){
            if(operators.size()==0 || operators.peek()=='(' ){
                operators.push(exp.charAt(i));
            }
            else if(precedence(exp.charAt(i) , operators.peek() ) ){
                operators.push(exp.charAt(i));
            }
            else{
                while(operators.size()>0 && operators.peek()!='(' && !precedence(exp.charAt(i) , operators.peek() ) ){
                    Character ch = operators.pop();
                    String s1 = operands.pop();
                    String s2 = operands.pop();
                    String s = s2+s1+ch;
                    // System.out.println("string : "+s);
                    operands.push(s);
                }
                
                operators.push(exp.charAt(i) );
            }
        }
        else if (exp.charAt(i)==')' ){
            
            while(operators.peek()!='(' ){
                String s1 = operands.pop();
                String s2 = operands.pop();
                Character ch = operators.pop();
                String s = s2+s1+ch;
                // System.out.println("string : "+s);
                operands.push(s);
            }
            operators.pop();
        }
        else if (exp.charAt(i)=='(' ){
            operators.push('(');
        }
        else{
            operands.push(Character.toString( exp.charAt(i)) );
        }
    }
    while(operators.size()!=0 ){
        String s1 = operands.pop();
        String s2 = operands.pop();
        Character ch = operators.pop();
        String postfix = s2+s1+ch;
        operands.push(postfix);
    }
    
    System.out.println(operands.pop() );
 }
 
 public static boolean precedence(Character exp , Character op){
    if(exp=='+' || exp=='-'){
        return false;
    }
    else{
        if(op=='+'||op=='-'){
            return true;
        }else{
            return false;
        }
    }
 }
}