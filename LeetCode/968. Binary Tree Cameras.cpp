/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //you need camera -1
    //you have camera 0
    //you are covered 1
    
    int ans=0;
    int  solve(TreeNode* p){
        if(p==NULL)
            return 1;//u r covered
        int l,r;
        l=solve(p->left);
        r=solve(p->right);
        if(l==-1 || r==-1){
            ans++;
            return 0;//now i have camera
        }
        if(l==1 && r==1)//both are covered
            return -1;
        if(l==0 || r==0)
            return 1;
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        ans=0;
        int x=solve(root);
        if(x==-1)
            ans++;//root need camera
        return ans;
    }
};