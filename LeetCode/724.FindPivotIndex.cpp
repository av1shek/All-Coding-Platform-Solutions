class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      int k=nums.size();
      int rightsum = 0;
        int leftsum = 0;
      for(int i=0;i<k;i++){
          rightsum+=nums[i];
      }
      for(int i=0;i<k;i++){
           rightsum-=nums[i];
          if(rightsum==leftsum){
             
              return i;
          }
          leftsum+=nums[i];
          
      }
        return -1;
    }
    
};
