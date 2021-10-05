class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 2)
            return n;
        int ans[n + 1];
        ans[0] = 1, ans[1] = 1, ans[2] = 2;
        for (int i = 3; i <= n; ++i)
        {
            ans[i] = ans[i - 1] + ans[i - 2];
            // cout<<ans[i]<<" ";
        }
        // cout<<endl;
        return ans[n];
    }
};
