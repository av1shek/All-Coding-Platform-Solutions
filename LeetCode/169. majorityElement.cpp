// Contributed by : RajatRathore123-github

// Given an array nums of size n, return the majority element.

/*The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.*/

#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
        int count = 0;
        int value = 0;
        for(int num : nums){
            if(count == 0){
                value = num;
            }
            if(num == value){
                count += 1;
            }
            else{
                count -= 1;
            }
        }
        return value;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n ;i++){
        cin >> nums[i];
    }
    cout << "majority element is : " << majorityElement(nums) << endl;
}
