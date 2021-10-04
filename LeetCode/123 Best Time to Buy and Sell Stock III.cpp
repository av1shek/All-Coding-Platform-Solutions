class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int n=prices.size();
        // this soln for any genral case when k is anythin
        // int dp[3][n+1];
        // for(int i=0;i<3;i++)
        //     dp[i][0]=0;
        // for(int j=0;j<n;j++)
        //     dp[0][j]=0;
        // for(int k=1;k<=2;k++)
        // {
        //     int mini=prices[0];
        //     for(int i=1;i<n;i++)
        //     {
        //         mini=min(mini,prices[i]-dp[k-1][i-1]);
        //         dp[k][i]=max(dp[k][i-1],prices[i]-mini);
        //     }
        // }
        // return dp[2][n-1];
        
        // when k=2
        int bu1=INT_MAX,buy2=INT_MAX;
        int sell1=0,sell2=0;
        for(auto &it:prices)
        {
            bu1=min(bu1,it);
            sell1=max(sell1,it-bu1);
            buy2=min(buy2,it-sell1);
            sell2=max(sell2,it-buy2);
        }
        return sell2;
        
    }
};