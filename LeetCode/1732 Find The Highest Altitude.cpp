class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int p=0,m=0;
        for(auto g: gain){
            p += g;
            m = max(m, p);
        }
        return m;
    }
};