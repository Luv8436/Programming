// 1. You are given an infix expression.
// 2. You are required to evaluate and print it's value.
// Input Format
// Input is managed for you
// Output Format
// Value of infix expression
// Constraints
// 1. Expression is balanced
// 2. The only operators used are +, -, *, /
// 3. Opening and closing brackets - () - are used to impact precedence of operations
// 4. + and - have equal precedence which is less than * and /. * and / also have equal precedence.
// 5. In two operators of equal precedence give preference to the one on left.
// 6. All operands are single digit numbers.
// Sample Input
// 2 + 6 * 4 / 8 - 3
// Sample Output
// 2

import java.io.*;
import java.util.*;

public class Main{
  

public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String exp = br.readLine();

    // code
    Stack<Integer> operands = new Stack<>();
    Stack<Character> operators = new Stack<>();
    
    for(int i=0;i<exp.length();i++ ){
        if(exp.charAt(i)==' ' )
        continue;
        if(exp.charAt(i)=='+'||exp.charAt(i)=='-'||exp.charAt(i)=='*'||exp.charAt(i)=='/' ){
            if(operators.size()==0 || precedence(exp.charAt(i) , operators.peek() ) ){
                operators.push(exp.charAt(i) );
            }else{
                while(operators.size()>0 && operators.peek()!='(' && !precedence(exp.charAt(i) , operators.peek()) ){
                    Integer a = operands.pop();
                    Integer b = operands.pop();
                    Character ch = operators.pop();
                    operands.push(operation(a , b , ch) );
                }
                operators.push(exp.charAt(i) );
            }
        }
        else if(exp.charAt(i)==')'){
            while(operators.peek()!='(' ){
                Integer a = operands.pop();
                Integer b = operands.pop();
                Character ch = operators.pop();
                operands.push(operation(a , b , ch) );
            }
            operators.pop();
        }
        else if(exp.charAt(i)=='('){
            operators.push('(');
        }
        else{
            operands.push(exp.charAt(i)-'0' );
        }
        
        // System.out.println("operands : "+operands);
        // System.out.println("operators : "+operators);
    }
    while(operators.size()>0 )
    {
        Integer a = operands.pop();
        Integer b = operands.pop();
        Character ch = operators.pop();
        operands.push(operation(a , b , ch) );
    }
    System.out.println(operands.peek() );
 }
 
 public static int operation(int a , int b , int ch){
    if(ch=='+'){
        return a+b;
    }else if(ch=='-'){
        return b-a;
    }else if(ch=='*'){
        return b*a;
    }else if(ch=='/'){
        return b/a;
    }
    return 0;
 }
 public static boolean precedence(char exp , char stack){
    if(exp=='+'||exp=='-' ){
        return false;
    }else{
        if(stack=='+'||stack=='-'){
            return true;
        }else{
            return false;
        }
    }
 }
 
}