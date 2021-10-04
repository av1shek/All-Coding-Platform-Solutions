class Solution {
public:
    int vis[301][301];
    void dfs(vector<vector<char>>& grid,int i,int j,int n,int m)
    {
        if(i<0 or i>=m or j<0 or j>=n or vis[i][j]==1 or grid[i][j]=='0')
            return ;
        vis[i][j]=1;
        dfs(grid,i+1,j,n,m);
        dfs(grid,i-1,j,n,m);
        dfs(grid,i,j-1,n,m);
        dfs(grid,i,j+1,n,m);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        memset(vis,-1,sizeof(vis));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                if(grid[i][j]=='1' and vis[i][j]!=1)
                    ans++,dfs(grid,i,j,n,m);
                    
        }
        return ans;
    }
};