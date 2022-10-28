#include <iostream>
using namespace std;
int main(){
   long long int n;
    cin>>n;
    while(n!=1){
          cout<<n<<" ";
          if(n&1)
              n = n*3;
              n= n + 1;
            else 
               n/=2;
    }

    cout<<n<<" ";

}