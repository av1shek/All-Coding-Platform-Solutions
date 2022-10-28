#include <iostream>
#include<climits>
using namespace std;


int main() {
 int t;
 cin>>t;
 while(t--)
 {
     int a,ans=0;
     cin>>a;
     string A,B;
     cin>>A;
     cin>>B;
     
     
     int a1[26]={0};
     int a2[26]={0};
     for (int i=0;i<a;i++){
         int n=A[i]-'a';
         a1[n]++;
         a2[B[i]-'a']++;
         
     }
     for (int i=0;i<26;i++){
         ans=max(ans,min(a1[i],a2[i]));
     }
     cout<<ans<<endl;
       
        }
    
    
 
	return 0;
}
