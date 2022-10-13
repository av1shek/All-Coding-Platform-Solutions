//	4Sum Problem:- 
//Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

//	0 <= a, b, c, d < n
//	a, b, c, and d are distinct.
//	nums[a] + nums[b] + nums[c] + nums[d] == target
//	You may return the answer in any order.
//
//  Example 1:
//
//  Input: nums = [1,0,-1,0,-2,2], target = 0
//  Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]  

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>>s;
        vector<vector<int>>ans;
        
        for(int i=0;i<n;i++){
            long long int t = target-nums[i];
            for(int j=i+1;j<n;j++){
                int f = j+1, l=n-1;
                while(f<l){
                    if((long long)nums[j]+nums[f]+nums[l]==t){
                        s.insert({nums[i], nums[j], nums[f], nums[l]});
                        f++;
                        l--;
                    }
                    else if((long long)nums[j]+nums[f]+nums[l]>t) l--;
                    else f++;
                }
            }
        }
        for(auto i : s){
            ans.push_back(i);
        }
        
        return ans;
    }
};
