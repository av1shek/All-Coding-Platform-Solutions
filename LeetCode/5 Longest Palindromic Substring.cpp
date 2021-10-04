class Solution {
public:
    string ans;
    string longestPalindrome(string s) {
        int n=s.size();
        bool dp[n][n];
        memset(dp,0,sizeof(dp));
        int maxlen=1;
        for(int i=0;i<n;i++)
            dp[i][i]=true;
        
           // check for sub-string of length 2
        int start=0;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=true;
                start=i;
                maxlen=2;
            }
        }
          // Check for lengths greater than 2.
    // k is length of substring
        for(int k=3;k<=n;k++)
        {
            for(int i=0;i<n-k+1;i++)
            {
                int j=i+k-1;
                if(s[i]==s[j] and dp[i+1][j-1])
                {
                    dp[i][j]=true;
                    if(k>maxlen)
                        maxlen=k,start=i;
                }
            }
        }
        
        for(int i=start;i<=start+maxlen-1;i++)
            ans.push_back(s[i]);
        return ans;
        
        
    }
};