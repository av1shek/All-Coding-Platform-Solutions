// 3 pointer and Binary Search Approach 
// Time Complexity: O(N log N + N³ logN)
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        sort(nums.begin(),nums.end());
      
       set<vector<int>> sv;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
    
                for(int k=j+1;k<n;k++)
                { 
                  
                   int x = (long long)target - 
                           (long long)nums[i]-
                           (long long)nums[j]-(long long)nums[k];
                   
                        if(binary_search(nums.begin()+k+1,nums.end(),x)){
                            vector<int> v;
                            v.push_back(nums[i]);
                            v.push_back(nums[j]);
                            v.push_back(nums[k]);
                            v.push_back(x);
                            sort(v.begin(),v.end());
                            sv.insert(v);
                        }
                }
            }
        }
        vector<vector<int>> res(sv.begin(),sv.end());
        return res;
    }
};

// Sort the Array Approach
// Time Complexity: O(n³) 
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       vector<vector<int>> res;
        int n = nums.size();
        if(n<1) return res;
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long int target2 = (long)target - (long)nums[i] - (long)nums[j];
                
                int front = j+1, back = n-1;
                
                while(front < back){
                    int two_sum = nums[front] + nums[back];
                    if(two_sum < target2){
                        front++;
                    }else if(two_sum > target2){
                        back--;
                    }else{
                        vector<int> quad;
                        quad.push_back(nums[i]);                
                        quad.push_back(nums[j]);
                        quad.push_back(nums[front]);
                        quad.push_back(nums[back]);
                        res.push_back(quad);
                        
                        while(front < back && nums[front] == quad[2]){
                            front++;
                        }
                        while(back > front && nums[back] == quad[3]){
                            back--;
                        }
                        
                    }
                }
                while(j+1 < n && nums[j+1] == nums[j]) j++;
            }
            while(i+1 < n && nums[i+1] == nums[i]) i++;
        }
        return res;
        
    }
};