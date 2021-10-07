class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int lk[n+1];
        lk[0]=0;
        lk[1]=nums[0];
        for(int i=2;i<n+1;i++)
        {
            lk[i]=max(lk[i-1],lk[i-2]+nums[i-1]);
        }
        return lk[n];
    }
};
