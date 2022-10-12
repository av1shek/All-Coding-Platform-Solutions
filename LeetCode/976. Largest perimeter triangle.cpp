class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        //sort in descending order
        sort(nums.rbegin(), nums.rend());
        int n= nums.size();
        
        //check every triplet from largest numbers
        for(int i=1;i<n-1;i++)
        {
            int a = nums[i-1], b= nums[i], c=nums[i+1];
            if(a<b+c) //if makes a triangle find perimeter
            {
                return a+b+c;
            }
        }
        return 0;
    }
};
