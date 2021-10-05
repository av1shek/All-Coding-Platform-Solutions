#include <bits/stdc++.h>

class Solution {
public:
    string convert(string s, int numRows) {
        vector<char> v[numRows];
        
        bool pry=false;
        int chk=0;
        if(numRows==1)
            return s;
        for(int i=0;i<s.size();i++)
        {
            
            if(chk==0)
                pry=true;
            if(chk==numRows-1)
                pry=false;
            
            
            v[chk].push_back(s[i]);
            
            if(pry==true)
                chk++;
            else
                chk--;
        }
        string ans="";
        for(int i=0;i<numRows;i++)
        {
            for(int j=0;j<v[i].size();j++)
            {
                ans+=v[i][j];
            }
        }
        return ans;
    }
};