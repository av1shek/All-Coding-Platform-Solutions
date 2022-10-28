#include <iostream>
using namespace std;
int main(){
    long long int n;
    cin>>n;
    long long sum  =  (n*(n+1))/2;
    if(sum&1)
        cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        int arr[n];
        for(int i=0; i<n; i++)
             arr[i] = i+1;
         sum/=2;
         int index = n-1;
         int count = 0;
         while(sum!=0){
              if(sum >= arr[index]){
                      sum-=arr[index];
                      arr[index]*=(-1);
                      index--;
                      count++;
               } 
            else 
                index = sum-1;
            }
        cout<<count<<endl;
       for(int i=0; i<n; i++){
          if(arr[i]<0)
                cout<<abs(arr[i])<<" ";
       }
        cout<<endl;
        cout<<n-count<<endl;
       for(int i=0; i<n; i++){
          if(arr[i]>0)
                cout<<arr[i]<<" ";
       }
        cout<<endl;
    }
           
    
}
