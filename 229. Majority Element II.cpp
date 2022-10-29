class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int t = n / 3;
        if (n == 1)
            return nums;
        vector<int> v;
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < n)
        {
            int c = 1;
            while (i < n - 1 && nums[i] == nums[i + 1])
            {
                c++;
                i++;
            }
            if (c > t)
                v.push_back(nums[i]);
            i++;
        }
        return v;
    }
};
