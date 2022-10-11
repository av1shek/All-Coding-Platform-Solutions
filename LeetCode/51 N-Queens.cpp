class Solution {
public:
   vector<vector<string>> res;
bool check(vector<string>& temp,int r, int c,int n){
    for(int i=0; i < r ;++i){
        if(temp[i][c] =='Q'){
            return false;
        }
    }
    int times=min(r,c);
    int i=r,j=c;
    while(times > 0){
        if(temp[--i][--j] =='Q'){
            return false;
        }
        times--;
    }
    times = n-max(r,c);
    i=r,j=c;
    for( ; i>= 0 && j < n ;--i,++j){
        if(temp[i][j]=='Q'){
            return false;
        }
    }
    return true;
}
void helper(vector<string>temp,int r,int n){
    if(r == n){
        res.push_back(temp);
        return;
    }
    
    for(int i = 0; i < n; ++i){
        if(check(temp,r,i,n)){
            temp[r][i]='Q';
            helper(temp,r+1,n);
            temp[r][i]='.';
        }
    }

}
vector<vector<string>> solveNQueens(int n) {
    vector<string> temp;
    string temp1="";
    for(int i=0; i <n; ++i){
        temp1+='.';
    }
    for(int i=0; i <n; ++i){
        temp.push_back(temp1);
    }

    helper(temp,0,n);
    return res;
}
};