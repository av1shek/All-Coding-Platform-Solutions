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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode *x;
        int sum=INT_MIN,currsum=0,level=0,ans;
        q.push(root);
        while(!q.empty()){
            currsum=0;
            int n=q.size(),i=0;
            for(i=0;i<n;i++){
            x=q.front();
            q.pop();
                currsum+=x->val;
                if(x->left)
                    q.push(x->left);
                if(x->right)
                    q.push(x->right);
            
            }
            level++;
           // cout<<currsum<<" ";
            if(currsum>sum){
                sum=currsum;
            ans=level;
            }
        }
        return ans;
    }
};