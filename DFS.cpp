#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int s){
    visited[s] = true;
    cout << s << " ";
    for(auto to: adj[s]){
        if(!visited[to]){
            dfs(to);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    adj.assign(n);
    visited.assign(n, false);
    
    for(int i=0; i<m; ++i){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0; i<n; ++i){
        if(!visited[i]){
            dfs(i);
        }
    }
    
    return 0;
    
}
