class Solution {
public int[] intersection(int[] nums1, int[] nums2) {
HashSet m = new HashSet<>();

    for(int i=0;i<nums1.length;i++){
        m.add(nums1[i]);
    }
    int k =0;
    int arr[] = new int [1000];
    for(int i=0;i<nums2.length;i++){
        if(m.contains(nums2[i]) == true){
            int data = nums2[i];
            arr[k] = data;
             m.remove(data);
            k++;
        }
    }
    int ans[] = new int[k];
    for(int i=0;i<k;i++){
        ans[i] = arr[i];
    }
    return ans;
}
}
