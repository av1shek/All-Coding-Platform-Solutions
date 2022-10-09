class Solution {
public:
    vector<vector<int>> permute(vector<int>& v) {
        sort(v.begin(),v.end());
        vector<vector<int>>p;
        do{
            p.push_back(v);
        }while(next_permutation(v.begin(),v.end()));
        return p;
    }
};
