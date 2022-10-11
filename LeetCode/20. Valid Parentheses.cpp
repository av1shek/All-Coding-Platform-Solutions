#include <iostream>
using namespace std;
#include <stack>


class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(char c:s){
            if(stk.empty())
                stk.push(c);
            else if( (c==')' && stk.top()=='(') || (c=='}' && stk.top()=='{') || (c==']' && stk.top()=='[') )
                stk.pop();    
            else
                stk.push(c);
        }
        if(!stk.empty())
            return false;
        return true;
    }
};