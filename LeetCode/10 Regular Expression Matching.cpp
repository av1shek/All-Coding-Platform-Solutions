class Solution {
public:
    vector<vector<bool>>dp;
    bool isMatch(string s, string p) {
        int n = s.length(),m=p.length();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        dp[0][0] = true;
        for(int j=1;j<=m;j++){
            if(p[j-1]=='*')dp[0][j] = dp[0][j-2];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[j-1]=='*'){
                    dp[i][j] = ((s[i-1]==p[j-2] || p[j-2]=='.') && dp[i-1][j]);
                    dp[i][j] = (dp[i][j] || dp[i][j-2]);
                }else if((s[i-1]==p[j-1]) || p[j-1]=='.'){
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        return dp[n][m];
    }
};