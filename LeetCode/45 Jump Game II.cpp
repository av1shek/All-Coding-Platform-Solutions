class Solution {
public:
    int helper(vector<int>& nums,vector<int>& lk,int n)
    {
        if(n>=nums.size()) return INT_MAX;
        if(n==nums.size()-1) return 0;
        if(nums[n]==0) return INT_MAX;
        if(lk[n]!=-1) return lk[n];
        lk[n]=INT_MAX-1;
        for(int i=1;i<=nums[n];i++)
        {
            lk[n]=min(lk[n],helper(nums,lk,n+i));
        }
        return ++lk[n];
    }
    int jump(vector<int>& nums) {
        vector<int> lk(nums.size()+1,-1);
        return helper(nums,lk,0);
    }
};
