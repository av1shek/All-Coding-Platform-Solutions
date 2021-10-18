class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = -prices[0], sell = 0, cool = 0;
        for(int i=1;i<prices.size();i++)
        {
            if(cool - prices[i] > buy)
                buy = cool - prices[i];
            cool = sell;
            if(buy + prices[i] > sell)
                sell = buy + prices[i];
            
        }
        return sell;
    }
};
