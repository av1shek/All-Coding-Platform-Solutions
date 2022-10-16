/*
Simple Bruteforce approach, consider each number from 0 to n and 
check if its reverse add it to give the value of n or not.
*/

class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for(int i = 0; i <= num; ++i){
            int n = i;
            int r = 0;
            while(n){
                r = r*10 + n%10;
                n = n/10;
            }
            if(r + i == num) return true;
        }
        return false;
    }
};
