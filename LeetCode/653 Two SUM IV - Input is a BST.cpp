class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
    stack<TreeNode *> stk1, stk2;
    TreeNode *cur1 = root, *cur2 = root;
    int lo = 0, hi = 0;
    while (cur1) stk1.emplace(cur1), lo = cur1->val, cur1 = cur1->left;
    while (cur2) stk2.emplace(cur2), hi = cur2->val, cur2 = cur2->right;
    while (lo < hi) {
        int sum = lo + hi;
        if (sum < k) { // move cur1, increase lo
            while(cur1) stk1.emplace(cur1), lo = cur1->val, cur1 = cur1->left;
            lo = stk1.top()->val, cur1 = stk1.top()->right, stk1.pop(); 
        } else if (sum > k) { // move cur2, decrease hi
            while(cur2) stk2.emplace(cur2), hi = cur2->val, cur2 = cur2->right;
            hi = stk2.top()->val, cur2= stk2.top()->left, stk2.pop();
        } else { return true; }
    }
    return false;
}
};