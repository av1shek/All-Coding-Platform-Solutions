class Solution {
public:
    void nextPermutation(vector<int>& nums) {
	    // Optimal Solution Time O(N) & Auxiliary Space O(1)
	  
        int len=nums.size(), k=0, l=0;   // For example, if nums=[2,4,6,5,3]
        for(k=len-2;k>=0;k--){
            if(nums[k]<nums[k+1])
                break;  // k will point to 4 in nums=[2,4,6,5,3]
        }
        if(k<0){
            reverse(nums.begin(),nums.end());
        }
        else{
            for(l=len-1;l>k;l--){
                if(nums[l]>nums[k])
                    break; //  l will point to 5 in nums=[2,4,6,5,3]
        }
            swap(nums[k],nums[l]); // nums=[2,5,6,4,3]
            reverse(nums.begin()+k+1,nums.end()); // nums=[2,5,3,4,6]
        }
    }
};
