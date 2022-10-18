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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
        {
            return ans;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int size=q.size();
            vector<int> v;
            
            for(int i=0;i<size;i++)
            {
                TreeNode* res=q.front();
                q.pop();
                
                if(res->left)
                {
                    q.push(res->left);
                }
                if(res->right)
                {
                    q.push(res->right);
                }
                v.push_back(res->val);
            }
            ans.push_back(v);
        }
        return ans;
    }
};
