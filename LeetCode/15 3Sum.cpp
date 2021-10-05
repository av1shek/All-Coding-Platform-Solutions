// Given an integer array nums, return all the triplets[nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

//Notice that the solution set must not contain duplicate triplets.

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> vans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i != nums.size(); ++i)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int sum = -(nums[i]);
        int j = i + 1, k = nums.size() - 1;
        while (j < k)
        {
            if (nums[j] + nums[k] < sum)
            {
                ++j;
            }

            else if (nums[j] + nums[k] == sum)
            {
                if (!(j > i + 1 && nums[j] == nums[j - 1]))
                    vans.push_back({nums[i], nums[j], nums[k]});
                ++j;
                --k;
            }
            else
            {
                --k;
            }
        }
    }

    return vans;
}
