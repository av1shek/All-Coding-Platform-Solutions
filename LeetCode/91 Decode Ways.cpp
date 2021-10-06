class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        if(s[0]=='0')  return 0;
        int lk[n+1]; 
        memset(lk,0,sizeof(lk));
        lk[0]=1;
        lk[1]=1;
        for(int i=2;i<n+1;i++)
        {
            if(stoi(s.substr(i-2,2))<=26 && s[i-2]!='0') lk[i]+=lk[i-2];
            if(s[i-1]!='0') lk[i]+=lk[i-1];
        }
        return lk[n];
    }
};
