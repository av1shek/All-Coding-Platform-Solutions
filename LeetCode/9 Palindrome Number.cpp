class Solution {
public:
    bool isPalindrome(int x) {

        if(x==0){
            return true;
        }
        if(x%10==0 ){
            return false;
        }
        int reversed = 0;
        while(x>reversed){
            int pop = x%10;
            x /= 10;
            reversed = (reversed*10) + pop;
        }
        if(x == reversed || x == reversed/10){
            return true;
        }else{
            return false;
        }

    }
};
