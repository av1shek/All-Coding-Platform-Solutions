class Solution {
public:
    int minMoves(int t, int d) {
        int c=0;
        while(t!=1){
            if(t%2==0 && d!=0){
                t/=2;
                d--;
                c++;
                continue;
            }
            if(d!=0){
                t--;
                c++;
            }
            else{
                c+=t-1;
                break;
            }
        }
        return c;
    }
};