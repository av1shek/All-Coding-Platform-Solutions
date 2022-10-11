class Solution {
public:
     int dx[4] = {-1, 1, 0, 0}; //dx[] and dy[] are used to move into 4 directions
    int dy[4] = {0, 0, -1, 1};
    
    bool isValid(int x,int y,vector<vector<bool>> & vis)
    {
        int n=vis.size();int m=vis[0].size();
          return((x>=0)and  (y>=0) and (x<n) and (y<m) and (!vis[x][y]));
    }
    
    
     void DFS(vector <vector <int>>& A, int row, int col,queue<pair<int,int>> &q,vector<vector<bool>> & vis) //DFS to store 1st island's positions in a queue
    {
        vis[row][col] = true;
        q.push({row, col});
        for(int i=0; i<4; i++)
        {
            int x = row+dx[i];
            int y = col+dy[i];    
            if(isValid(x, y,vis) && (A[x][y] == 1))
                DFS(A, x, y,q,vis);
        }
    }
    
   
    
    int shortestBridge(vector<vector<int>>& grid) {
    // we will use dfs and Bfs dfs for making all the island of one type make it marked at type 2 and push it in queue 
        // after pushing in queue add to to all index of island type 2
        
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        bool found=false;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        // memset(vis,false,sizeof(vis));
        
        // these loops is run for first index wheere it is 1 and form that index we will run dfs and all the index adject to that index or that island we will make it to 2
        for(int i=0;i<n;i++)
        {
            if(found)
                break;
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    DFS(grid,i,j,q,vis);
                    found=true;
                    break;
                }
            }
        }
        
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //         cout<<vis[i][j]<<" ";
        //     cout<<endl;
        // }
        
        // now one of the island is marked as 2 and all their index is in queue so we run Bfs from all that index (like level wise travsal ) untill we reached to another island
        int bridge=0;
        while(!q.empty())
        {
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int newX=x+dx[i];
                    int newY=y+dy[i];
                    if(isValid(newX,newY,vis))
                    {
                        if(grid[newX][newY]==1)
                            return bridge;
                        q.push({newX,newY});
                        vis[newX][newY]=true;
                    
                    }
                }
            }
            bridge++;
        }
        
        return -1;
    }
};