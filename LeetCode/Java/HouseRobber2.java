class HouseRobber2 {
    public int rob(int[] nums) {
        if(nums.length==1)
            return nums[0];
        int n=nums.length;
        int copy[]=new int[n-1];
        for(int i=0;i<n-1;i++)
        {
            copy[i]=nums[i+1];
        }
        nums[n-1]=0;
        return Math.max(find(nums),find(copy));
    }
    int find(int nums[])
    {
        if(nums.length==1)
            return nums[0];
         int n=nums.length;
        int max[]=new int[n+1];
        max[n]=0;
        max[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            max[i]=Math.max(max[i+1],max[i+2]+nums[i]);
        }
        return max[0];
    }
}