import java.util.Stack;
class Solution {
    public int kthSmallest(TreeNode root, int k) {
        if(root==null)
            return Integer.MAX_VALUE;
        Stack<TreeNode> s=new Stack<>();
        TreeNode n;
        n=root;
        while(n!=null||!s.isEmpty())
        {
            if(n!=null)
            {
                s.push(n);
                n=n.left;
            }
            else
            {
                n=s.pop();
                k--;
                if(k==0)
                    return n.val;
                n=n.right;
            }
        }
        return Integer.MAX_VALUE;
    }
}