class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {

        vector<int> ind(n,0);
        vector<vector<int>> adj(n);
        
        for(auto i:prerequisites){
            
            int a = i[0], b = i[1];
            // b is pre_req for a
            
            ind[b]++;
            adj[a].push_back(b);
        }
        
        vector<int> ans;
        
        queue<int> q;
        for(int i = 0;i<n;i++){
            if(!ind[i]){
                q.push(i);
                ans.push_back(i);
            }
        }
        
        if(q.empty()) return {};
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            
            for(int nbr:adj[node]){
                
                if(ind[nbr] == 0) return {};
            
                ind[nbr]--;
                if(!ind[nbr])
                {
                    q.push(nbr);
                    ans.push_back(nbr);
                }
            }
        }
        
        
        for(int x:ind) if(x) return {};
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
