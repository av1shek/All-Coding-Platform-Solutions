#define ll long long
class NumArray {
    
    vector<ll> bit;
    vector<int> arr;
    
    ll query(ll idx){
        ll ans = 0;
        while(idx > 0){
            ans+=bit[idx];
            idx = ( idx - (idx&-idx) );
        }
        return ans;
    }
    
    void upd(ll idx, ll val){
        while(idx<bit.size()){
            bit[idx]+=val;
            idx = (idx + (idx&-idx));
        }
    }
    
public:
    NumArray(vector<int>& nums) {
        bit.clear();
        bit.resize(nums.size() + 2);
    
        arr = nums;
        
        for(int i = 0;i<nums.size();i++){
            upd(i+1, nums[i]);
        }
        
    }
    
    void update(int index, int val) {
        ll dif = val - arr[index];
        arr[index] = val;
            
        upd(index + 1, dif);
    }
    
    int sumRange(int left, int right) {
        return query(right+1) - query(left);
    }
};
