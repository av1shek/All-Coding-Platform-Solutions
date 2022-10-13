class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
       int n=gas.length;
        int total_surplus=0;
        int s=0;//In the tank
        int start=0;
        for(int i=0;i<n;i++)
        {
            total_surplus+=gas[i]-cost[i];
            s=s+gas[i]-cost[i];
            if(s<0)
            {
                start=i+1;
                s=0;
                
            }
            }
        return total_surplus<0?-1:start;
       
    }
}
