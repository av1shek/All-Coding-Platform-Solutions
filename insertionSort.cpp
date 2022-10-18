include<iostream>
#include<vector>
using namespace std;
void insertionSort(vector<int>&arr){
  for(int i=1;i<arr.size(); i++){
    int key=arr[i];
    int j=i-1;
    while(j>=0&&arr[j]>key){
      arr[j+1]=arr[j];
      j--;
      arr[j+1]=key;
    }


}
  for(int ele:arr){
     cout<<ele<<" ";


     }
     cout<<"\n";
 
 }



int main(){
  vector<int>arr={1,4,6,8,5,9};
  insertionSort(arr);

}
