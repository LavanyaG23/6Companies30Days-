//LEETCODE 150. Evaluate Reverse Polish Notation


/*You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.
 */

class Solution {
public:
    int evaluate(int a, int b,string y){
        if(y=="+") return b+a;
        if(y=="-") return b-a;
        if(y=="*") return long(a)*b;
        return b/a;
        }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto&x:tokens){
            if(x=="+"||x=="-"||x=="*"||x=="/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(evaluate(a,b,x));
            }
            else{
                st.push(stoi(x));
            }
        }
        return st.top();
    }
};