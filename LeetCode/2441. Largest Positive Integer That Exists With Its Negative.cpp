#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxK(vector<int>& nums) {
		// keep track of maximum
        int maxi = INT_MIN;
		// set to remeber the other value 
        unordered_set<int> s;
        for(auto i : nums){
            if(s.find(i * -1) == s.end()){
				// if not found insert
                s.insert(i);
            }else{
				// if found update maxi 
                maxi = max(maxi, abs(i));
            }
        }
		// if not present return -1 else return maxi
        return maxi == INT_MIN ? -1 : maxi;
    }
};
//  time complexiy O(n) 
// space complexity O(n)
