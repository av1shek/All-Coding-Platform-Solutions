class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& arr) {
        
        int n = arr.size();
        
        vector<pair<int,int>> v;
        
        for(int i = 0; i<n;i++){
            v.push_back({ arr[i][0], arr[i][2] });
            v.push_back({ arr[i][1], -1*arr[i][2] });
        }

        sort(v.begin(), v.end());
        
        int prev = 0;
        
        map<int,int> mp;
        vector<vector<int>> ans;
        
        int i = 0;
        
        while(i<v.size()){
            
            int pp = v[i].first;
            
            while(i < v.size() && v[i].first == pp){
                int p = v[i].first;
                int h = v[i].second;

                if(h < 0){
                    // pull out
                    mp[-1*h]--;
                    if(!mp[-1*h]) mp.erase(-1*h);
                    
                } else {
                    mp[h]++;
                }
                
                i++;
            }
            
            int hmax;
            
            if(mp.size()){
                auto it = mp.end(); it--;
                hmax = it->first;
            } else {
                hmax = 0;
            }

            if( hmax != prev ){
                prev = hmax;
                ans.push_back({ pp, hmax });
            }
            
        }
        
        return ans;
    };
};
