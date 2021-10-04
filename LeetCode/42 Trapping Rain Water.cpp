class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n==1 or n==0)
        {
            return 0;
        }
        int mxl[n],mxr[n];
        mxl[0]=height[0];mxr[n-1]=height[n-1];
        int maxil=height[0];
        for(int i=1;i<n;i++)
        {
              maxil=max(maxil,height[i]);
                  mxl[i]=maxil;
        }
        int maxir=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            maxir=max(maxir,height[i]);
            mxr[i]=maxir;
        }
        int water[n];
        for(int i=0;i<n;i++)
            water[i]=min(mxr[i],mxl[i])-height[i];
        int ans=0;
        for(int i=0;i<n;i++)
        ans+=water[i];
        return ans;
    }
};