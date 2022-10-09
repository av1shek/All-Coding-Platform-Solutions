class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int prev = nums[0] + nums[1] + nums[2];
        
        for(int i=0;i<nums.size();i++)
        {
            int low = i+1;
            int high = nums.size() - 1;
            
            int curr = prev;
            while(low < high)
            {
                curr = nums[i] + nums[low] + nums[high];
                if(curr < target) low++;
                else if(curr > target) high--;
                else return target;
                
                if(abs(target - prev) > abs(target - curr))
                    prev = curr;
            }
            if(abs(target - prev) > abs(target - curr))
                    prev = curr;

        }
        return prev;
    }
};