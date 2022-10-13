
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
*/
/**
 * Problem Link- https://leetcode.com/problems/recover-binary-search-tree/
 * Problem Description-
 * You are given the root of a binary search tree (BST), where the values of exactly two nodes 
 * of the tree were swapped by mistake. Recover the tree without changing its structure.
 */
import java.util.*;
class RecoverBinarySearchTree_Probelm_99 {
    static TreeNode first,last,mid,prev;
    public void recoverTree(TreeNode root) {
        correct(root);
    }
    static void correct(TreeNode n)
    {
        first=mid=last=prev=null;
        if(n==null)
            return;
        correct2(n);
        if(first!=null&&last!=null)
        {
            int temp=first.val;
            first.val=last.val;
            last.val=temp;
        }
        else if(first!=null&&last==null)
        {
            int temp=first.val;
            first.val=mid.val;
            mid.val=temp;
        }
    }
    static void correct2(TreeNode n)
    {
        if(n==null)
            return;
        else
        {
            correct2(n.left);
            if(prev!=null&&prev.val>n.val)
            {
                if(first==null)
                {
                    first=prev;
                    mid=n;
                }
                else
                    last=n;
            }
            prev=n;
            correct2(n.right);
        }
    }
}