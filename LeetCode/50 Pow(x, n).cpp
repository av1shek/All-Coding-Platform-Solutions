class Solution {
public:
    double myPow(double x, int n)
    {
        double answer=cal(x,llabs(n));
        if(n>0) return answer;
        else return 1/answer;
    }
    double cal(double x,long long int n)
    {
        if(n==0) return 1;
        else
        {
            double temp=cal(x,n/2);
            if(n%2==0) return temp*temp;
            else return x*temp*temp;
        }
    }
};
