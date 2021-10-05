using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       
        vector<int> ans(nums1.size()+nums2.size());
        
        merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),ans.begin());
        
        int a=ans.size();
        
        if(a==1)
        {
            return ans[0];
        }
        else if(a%2!=0)
        {
            return ans[a/2]/1.0;
        }
        else
        {
            return (ans[(a/2)-1]+ans[a/2])/2.0;
        }
        
    }
};