class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        if (nums.empty())
            return res;
    
        sort(nums.begin(),nums.end());
    
        for (int i = 0; i < nums.size(); i++) {
           long long target_3 = (long long)target - (long long) nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                long long target_2 = (long long) target_3 - (long long) nums[j];
                int front = j + 1;
                int back = nums.size() - 1;
            
                while(front < back) {
                    int two_sum = nums[front] + nums[back];
                    if (two_sum < target_2) front++;
                    else if (two_sum > target_2) back--;
                    else {
                        vector<int> quad(4, 0);
                        quad[0] = nums[i];
                        quad[1] = nums[j];
                        quad[2] = nums[front];
                        quad[3] = nums[back];
                        res.push_back(quad);
                        while (front < back and nums[front] == quad[2]) 
                            ++front;
                        while (front < back and nums[back] == quad[3])
                            --back;
                    }
                }
                while(j + 1 < nums.size() and nums[j + 1] == nums[j]) 
                    ++j;
            }
            while (i + 1 < nums.size() and nums[i + 1] == nums[i]) 
                ++i;
        }
        return res;
    }
};