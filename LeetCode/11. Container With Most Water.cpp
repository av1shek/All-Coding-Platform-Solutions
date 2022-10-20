class Solution {
public:
    int maxArea(vector<int>& height) {
        int lb=0,ub=height.size()-1,ans=0,curr;
        while(lb<ub)
        {
            curr=(ub-lb)*(min(height[ub],height[lb])); 
            ans = max(ans, curr);
            if(height[ub]>height[lb]) 
                lb++;
            else           
                ub--;
        }
        return ans;
    }
};