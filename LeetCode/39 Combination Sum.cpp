class Solution {
public:
    void helper(vector<vector<int>>&res, vector<int>&temp,vector<int>& candidates,int sum,int target,int index){
        if(sum > target){
            return;
        }
        if(sum == target){
            res.push_back(temp);
            return;
        }
        int size=candidates.size();
        for(int i=index; i < size;++i ){
            temp.push_back(candidates[i]);
            helper(res,temp,candidates,sum+candidates[i],target,i);
            temp.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        helper(res,temp,candidates,0,target,0);
        return res;

    }
};