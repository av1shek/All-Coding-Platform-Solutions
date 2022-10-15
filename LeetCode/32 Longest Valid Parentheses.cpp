class Solution {
public:
    int longestValidParentheses(string s) {
     
        int n=s.length();
        int left=0,right=0;
        int mx=0,i=0;
        for(i;i<n;i++)
        {
            
            
            if(s[i]=='(')
                left++;
            else
                right++;
            if(left==right)
                mx=max(mx,2*left);
            else if(right>=left)
            {
                left=0;
                right=0;
            }
        }
        i=n-1;
        left=0,right=0;
        for(i;i>=0;i--)
        {
            
            if(s[i]=='(')
                left++;
            else
                right++;
            if(left==right)
                mx=max(mx,2*left);
            else if(left>=right)
            {
                left=0;
                right=0;
            }
        }
        return mx;
    }
};
