#include <bits/stdc++.h>
using namespace std;
int main(){
    int t, count = 0, flag = 0;
    cin>>t;
    while(t--){
        int a[3];
        for(int i=0;i<3;i++){
            cin>>a[i];
        }
        for(int i=0;i<3;i++){
            if(a[i] == 1){
                count++;
            }
        }
        if(count >=2){
            flag++;
        }
        count = 0;

    }
    cout<<flag;

}
