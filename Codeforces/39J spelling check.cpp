#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
 
vector<int> solve(string s1,string s2){
    int len=s2.length();
    vector<int> v;
    for(char x = 'a'; x <= 'z'; ++x){
        for(int i=0; i < s2.length() ;++i){
            string s= s2.substr(0,i) + x + s2.substr(i,len-i);
            if(s==s1){
                v.push_back(i);
            }
        }
    }
    return v;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    string s1,s2;
    cin>>s1>>s2;
    int m1[26]={0},m2[26]={0};
 
    for(int i=0; i < s1.length(); ++i){
        m1[s1[i]-'a']++;
    }
    for(int i=0 ; i<s2.length(); ++i){
        m2[s2[i]-'a']++;
    }
    int flag=0;
    char res;
    for(int i=0 ;i < 26; ++i){
        flag  += abs(m1[i] - m2[i]);
    }
    if( flag != 1){
        cout<<"0\n";
    }
 
    else{
        vector<int> v;
        for(int i=0;i<26; ++i){
            if(abs(m1[i] - m2[i]) == 1){
                res=i+97;
                break;
            }
        }
        for(int i=0;i<s1.length(); ++i){
            if(s1[i] != s2[i]){
                for(int j=i; j >=0; --j){
                    if(s1[i] == s1[j]){
                        v.push_back(j+1);
                    }
                    else{break;}
                }
                break;
            }
        }
        reverse(v.begin(),v.end());
        cout<<v.size()<<'\n';
        for(auto x: v){
            cout<<x<<' ';
        }
    }
 
    return 0;
}