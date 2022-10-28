#include <iostream>
using namespace std;
int main(){
    int t, n = 5;
    cin>>t;
    int ans = 0;
    while(n<=t){
        ans+=t/n;
         n*=5;
    }
     cout<<ans<<endl;
    return 0;
}