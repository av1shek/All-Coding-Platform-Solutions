#include <bits/stdc++.h>
using namespace std;
void Rahul(){
  string s;cin>>s;
  map<char,int>mp1,mp2,mp3;
  for(int i=0;i<s.size();i++){
    mp1[s[i]]=i;mp3[s[i]]++;
    if(mp2.find(s[i])==mp2.end())mp2[s[i]]=i;
  }
  vector<pair<int,char>>a,b;
  string res1,res2;
  for(auto [x,y]:mp2)a.push_back({y,x});
  for(auto [x,y]:mp1)b.push_back({y,x});
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  for(auto [x,y]:b){
    res2+=y;
  }
  for(int i=0;i<res2.size();i++){
    mp3[res2[i]]=mp3[res2[i]]/(i+1);
  }
  unordered_map<char ,int>mp;
  for(char c:s){
    if(mp3[c]>0){
      res1+=c;mp3[c]--;
      mp[c]=1;
    }
  }
  string t,t1=res1;
  for(int i=0;i<res2.size();i++){
    t+=t1;
    string k;
    for(char c:t1)if(c!=res2[i])k+=c;
    t1=k;
  }
  if(t!=s){
    cout<<-1<<endl;return;
  }
  cout<<res1<<" "<<res2<<endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  freopen("err.txt","w",stderr);
  #endif
  int t;cin>>t;
  while(t--)
  Rahul();
  return 0;
}