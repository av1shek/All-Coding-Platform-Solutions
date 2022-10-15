#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
         pair<int,int> thr = make_pair(INT_MAX,INT_MAX);
        int m;
        for(int i = 1;i < nums.size();i++){
            if(nums[i] > thr.second) return true;
            if((m = min(thr.first,nums[i-1])) < nums[i]){
                thr = make_pair(m,nums[i]); 
            }   
        }
        return false;
    }
};

int main()
{

    Solution mysol ;
    return 0;
}