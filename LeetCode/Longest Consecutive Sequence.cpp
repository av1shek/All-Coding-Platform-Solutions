  int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mySet;
        for(int i=0; i<nums.size(); i++)
            mySet.insert(nums[i]);
            
        int result = 0;
        while(mySet.size()>0)
        {
            int number = *mySet.begin();
            int count = 1;
            mySet.erase(number);
            int smaller = number-1;
            int bigger = number+1;
            while(mySet.count(smaller)>0)
            {
                mySet.erase(smaller);
                smaller--;
                count++;
            }
            while(mySet.count(bigger)>0)
            {
                mySet.erase(bigger);
                bigger++;
                count++;
            }
            
            result = max(result, count);
        }
        
        return result;
    }
