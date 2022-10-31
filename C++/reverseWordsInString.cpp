/*
557. Reverse Words in a String III

Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
*/
class Solution {
public:
    string reverseWords(string s) {
        int count=0;
       for(int i=0;i<s.size();i++){
           if(s[i]==' ' || s[i+1]=='\0'){
              
              reverse(s.begin()+count,s[i+1]=='\0'?s.end():s.begin()+i);
               count=i+1;
           }
       } 
        return s;
    }
};
