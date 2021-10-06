class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        vector<bool> m(nums.size() + 1, false);
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0 && nums[i] <= nums.size())
                m[nums[i]] = true;
        }
        for (int i = 1; i <= nums.size(); i++)
        {
            if (!m[i])
                return i;
        }
        return nums.size() + 1;
    }
};