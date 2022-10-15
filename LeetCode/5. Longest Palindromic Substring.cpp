class Solution {
public:
    string longestPalindrome(string s) {
        if(s==""){
            return s;
        }
        int len = s.length();
        int dp[1001][1001];
        for(int i=0;i<len;i++){
            dp[i][1]=1;
            dp[i][0]=0;
        }
        int maxi=1;int pos,lenn;
        for(int l=2;l<=len;l++){
            for(int i=0;i+l<=len;i++){
                if(s[i]==s[i+l-1] && dp[i+1][l-2]==l-2){
                    dp[i][l] = dp[i+1][l-2]+2;
                    if(maxi<dp[i][l]){
                        maxi = dp[i][l];
                        pos = i;
                        lenn = l;
                    }
                }else{
                    dp[i][l] = max(dp[i][l-1],dp[i+1][l-1]);
                }
            }
        }
        if(maxi==1){
            return s.substr(0,1);
        }
        return s.substr(pos,lenn);
    }
};
