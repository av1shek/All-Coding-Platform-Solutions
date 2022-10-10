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
    bool solve(TreeNode *root, int targetSum)
    {

        if(root->val==targetSum && root->left==NULL && root->right==NULL) return true;
        
        bool l=hasPathSum(root->left, targetSum-root->val);
        bool r=hasPathSum(root->right, targetSum-root->val);
        
        return l|r;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        return solve(root, targetSum);
    }
};