class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& arr, int k) {
      
        int m = arr.size(), n = arr[0].size();
        vector<pair<int,int>> vec;
        for(int i = 0;i<m;i++){
            int low = 0, high = n-1;
            int pos1 = -1;
            while(low <= high){
                int mid = low + (high-low)/2;
                if(arr[i][mid] == 1){
                    if(mid+1 > n-1 || arr[i][mid+1] == 0){
                        pos1 = mid;
                        break;
                    }
                    else{
                        pos1 = mid;
                        low = mid+1;
                    }
                }
                else high = mid-1;
            }
            vec.push_back({pos1, i});
        }
        vector<int> ans;
        sort(vec.begin(),vec.end());
        int i = 1;
        for(auto it : vec){
            ans.emplace_back(it.second);
            if(i == k) break;
            i++;
        }
        return ans;
    }
};