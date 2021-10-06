class Solution {
public:
    vector<vector<int>>cost;
    int64_t dp[101][101][101];
    int minCost(vector<int>& h,int n,int tar,int prev){
        if(n==0&&tar==0)return 0;
        if((n==0&&tar>0)||tar<0)return INT_MAX;
        if(h[n-1]!=0){
            if(h[n-1]==prev)return dp[n][tar][prev]=minCost(h,n-1,tar,h[n-1]);
            return dp[n][tar][prev]=minCost(h,n-1,tar-1,h[n-1]);
        }
        if(dp[n][tar][prev]!=-1)return dp[n][tar][prev];
        int res=INT_MAX;
        for(int i=0;i<cost[0].size();i++){
            h[n-1]=i+1;
            int k;
            if(h[n-1]==prev){
                k=minCost(h,n-1,tar,h[n-1]);
            }
            else k=minCost(h,n-1,tar-1,h[n-1]);
            if(k!=INT_MAX)res=min(res,cost[n-1][i]+k);
            h[n-1]=0;
        }
        return dp[n][tar][prev]=res;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& c, int m, int n, int target) {
        cost=c;
        memset(dp,-1,sizeof(dp));
        int k=minCost(houses,houses.size(),target,0);
        return k==INT_MAX?-1:k;
    }
};