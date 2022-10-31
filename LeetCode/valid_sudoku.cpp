class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int vis[10];
        
        for(int i=0;i<9;i++){
            memset(vis,0,sizeof(vis));
            for(int j =0;j<9;j++){
                if(board[i][j]!='.'){
                    if(vis[board[i][j]-'0']) return false;
                    else vis[board[i][j]-'0'] = 1;
                }
                
            }
        }
        
        for(int i=0;i<9;i++){
            memset(vis,0,sizeof(vis));
            for(int j =0;j<9;j++){
                if(board[j][i]!='.'){
                    if(vis[board[j][i]-'0']) return false;
                    else vis[board[j][i]-'0'] = 1;
                }
            }
        }
        
        int i =0;
        int j = 0;
        
        while(i<9){
            
            j = 0;
            
            while(j<9){
                memset(vis,0,sizeof(vis));
                for(int m=i;m<i+3;m++){
                    for(int n=j;n<j+3;n++){
                        if(board[m][n]!='.'){
                            if(vis[board[m][n]-'0']) return false;
                            else vis[board[m][n]-'0'] = 1;
                        }
                    }
                }
                
                j+=3;
            }
            
            i+=3;
        }
        
        return true;
        
    }
};
