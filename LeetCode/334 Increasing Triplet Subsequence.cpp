class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int t1=INT_MAX,t2=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=t1) t1=nums[i];
            else if(nums[i]<=t2) t2=nums[i];
            else
                return true;
        }
        return false;
    }
};
