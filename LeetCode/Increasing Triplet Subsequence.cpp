class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> lis;
        lis.push_back(nums[0]);
        for(int i=1;i<size(nums);i++)
        {
            if(nums[i]>lis.back())
                lis.push_back(nums[i]);
            else
            {
                auto it=lower_bound(begin(lis),end(lis),nums[i])-lis.begin();
                lis[it]=nums[i];
            }
        }
        
        
        return lis.size()>=3;
    }
};