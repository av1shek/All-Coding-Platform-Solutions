    int subarrayGCD(vector<int>& nums, int k) {
		int cnt = 0;
        for (int i = 0; i < size(nums); i++)
        {
            int currGcd = 0;
            for (int j = i; j < size(nums); j++)
            {
                currGcd = gcd(currGcd, nums[j]);
                if (currGcd == k) cnt++;
            }
        }
        return cnt;
    }
