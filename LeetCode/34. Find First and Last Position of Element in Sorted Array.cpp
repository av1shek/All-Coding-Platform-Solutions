class Solution {
public:
    int LB(vector<int> nums, int target){
        int l=0, h=nums.size()-1, mid, ans=-1;
        while(l<=h){
            mid=l+(h-l)/2;
            if(nums[mid]==target){
                ans= mid;
                h=mid-1;
            }
            else if(nums[mid]>target)
                h=mid-1;
            else 
                l=mid+1;
        }
        return ans;
    }

    int UB(vector<int> nums, int target){
        int l=0, h=nums.size()-1, mid, ans=-1;
        while(l<=h){
            mid=l+(h-l)/2;
            if(nums[mid]==target){
                ans= mid;
                l=mid+1;
            }
            else if(nums[mid]<target)
                l=mid+1;
            else 
                h=mid-1;
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = LB(nums, target);
        int ub = UB(nums, target);
        return {lb, ub};
    }
};