#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
int func1(int n){
   char n1[n];
    int tmp_cnt=0, cnt=0;
  //  cout<<n<<" 1\n";
      for (int j = 0; j < n; j++)
    {
        cin>>n1[j];
    }
for(int i = 0; i<n; i++) {
 
            if(n1[i] == 'A') {
                for(int j = i+1; j<=n; j++) {
                    if(n1[j] == 'P')
                        ++tmp_cnt;
                    else if(n1[j] == 'A') {
                        break;
                    }
                }
                if(tmp_cnt > cnt) {
                    cnt = tmp_cnt;
                }
                tmp_cnt = 0;
            }
        }
        cout << cnt << endl;
    return 0;
}

int main(){
    int t=0;
cin>>t;
int n[t];
for (int i = 0; i < t; i++)
{
    cin>>n[i];  
    func1(n[i]);
}
  return 0;
}