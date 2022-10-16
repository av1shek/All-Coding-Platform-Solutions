class Solution {
public:
    int reverse(int x) {
        bool flag = false;
        
        int num = 0;
        
        while(x)
        {
            if( (num > INT_MAX/10) || (num < INT_MIN/10) ) return 0;
            else num = num*10;
            
            if(x>0 && (num  > INT_MAX - x%10 )) return 0;
            else if( x<0 && (num < INT_MIN - x%10) ) return 0;
            else num += x%10;
            x = x/10;
        }
        return num;
    }
};
