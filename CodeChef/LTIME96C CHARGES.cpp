#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n;cin>>k;
        string s;cin>>s;
        if(n==1){
            while(k--){
                int q;cin>>q;
                cout<<"0"<<endl;
            }continue;
        }
        int sum = 0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1])sum+=2;
            else sum++;
        }
        while (k--){
            int q;cin>>q;
            q--;
            if(s[q]=='1'){
                s[q] ='0';
            }
            else s[q] ='1';
            if(q==0){
                if(s[q]==s[q+1]){
                    sum++;
                }
                else sum--;
            }
            else if(q==s.size()-1){
                if(s[q]==s[q-1]){
                    sum++;
                }
                else sum--;
            }
            else {
                if(s[q]==s[q+1]){
                    sum++;
                }
                else sum--;
                if(s[q]==s[q-1]){
                    sum++;
                }
                else sum--;
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}