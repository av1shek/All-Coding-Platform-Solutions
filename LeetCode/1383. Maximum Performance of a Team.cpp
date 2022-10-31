class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        long long int  ans=0,i=0,sum=0,mod=1000000007,z;
         priority_queue< long long int, vector< long long int>, greater< long long int> > pq;
        vector<pair< long long int, long long int>>vp;
        for(i=0;i<n;i++){
            vp.push_back({efficiency[i],speed[i]});
        }
         sort(vp.rbegin(), vp.rend());
        
        for(i=0;i<n;i++){
            sum+=vp[i].second;
            pq.push(vp[i].second);
            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
              z=vp[i].first*sum;
           // if(pq.size()==k)
            ans=max(ans,z);
        }
         return ans % (int)(1e9+7);
        
    }
};