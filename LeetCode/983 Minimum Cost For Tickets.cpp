class Solution {
public:
    vector<int> dp;
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return helper(0,0, days, costs);
    }
    
    int helper(int index,int validity, vector<int>& days, vector<int>& costs) {
        // if we reach nth index
        if(index>=days.size()) 
            return 0;
        
        // if we buy a ticket with validity greater than current day
        if(validity >= days[index])
            return helper(index+1, validity, days, costs);
        
        int mini = INT_MAX;
        // Taking 1 day ticket and adding cost to present cost
        mini = min(mini, costs[0]+helper(index+1, days[index], days, costs));
        // Taking 7 day ticket and adding cost to present cost
        mini = min(mini, costs[1]+helper(index+1, days[index]+6, days, costs));
        // Taking 30 day ticket and adding cost to present cost
        mini = min(mini, costs[2]+helper(index+1, days[index]+29, days, costs));
        
        // storing the minimum in dp
        return mini;
    }
};
