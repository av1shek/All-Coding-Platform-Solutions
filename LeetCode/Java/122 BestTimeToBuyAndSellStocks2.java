class Solution {
    public int maxProfit(int[] price) {
        int n=price.length;
        int profit[]=new int[n];
        profit[0]=0;
        int prev=price[0],max;
        int i;
        for(i=1;i<n;i++)
        {
            if(price[i]<prev)
            {
                prev=price[i];
                profit[i]=profit[i-1];
                continue;
            }
            profit[i]=profit[i-1]+price[i]-prev;
            prev=price[i];
        }
        return profit[n-1];
    }
}
