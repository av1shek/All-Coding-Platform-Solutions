class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> v;
        sort(intervals.begin(), intervals.end());
        
        vector<int> ex=intervals[0];
        int afirst=intervals[0][0];
        int asecond=intervals[0][1];
        
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] <=asecond){
                if(intervals[i][1]>asecond){
                    asecond=intervals[i][1];
                }
                ex={afirst, asecond};
            }else{
                v.push_back(ex);
                afirst=intervals[i][0];
                asecond=intervals[i][1];
                ex=intervals[i];
            }
        }
        v.push_back(ex);
        return v;
    }
};