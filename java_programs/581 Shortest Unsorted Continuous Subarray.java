public class Solution {
    public int findUnsortedSubarray(int[] nums) {
        int left = 0, right = -1;
        
        /// Find the rightmost number which is not in the correct potsition
        int max = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if(nums[i] < max) right = i;
            max = Math.max(max, nums[i]);
        }
        
        /// Find the leftmost number which is not in the correct potsition
        int min = nums[nums.length - 1];
        for (int j = nums.length - 2; j >= 0; j--) {
            if(nums[j] > min) left = j;
            min = Math.min(min, nums[j]);
        }
        
        return right - left + 1;
    }
}
