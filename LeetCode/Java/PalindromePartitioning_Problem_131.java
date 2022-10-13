/**
 * Leetcode Problem 131. Palindrome Partitioning
 * Problem Link- https://leetcode.com/problems/palindrome-partitioning/
 * Problem Description-
 * Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
 * A palindrome string is a string that reads the same backward as forward.
 */
import java.util.ArrayList;
import java.util.List;
class PalindromePartitioning_Problem_131 {
    public List<List<String>> partition(String s) {
        List<List<String>> ans=new ArrayList<>();
        make(ans,s,new ArrayList<String>());
        return ans;
    }
    public static void make(List<List<String>> ans,String s, List<String> ls)
    {
        if(s.length()==0)
        {
            ans.add(new ArrayList<String>(ls));
            return;
        }
        for(int i=0;i<s.length();i++)
        {
            if(check(s.substring(0,i+1)))
            {
                ls.add(s.substring(0,i+1));
                make(ans,s.substring(i+1,s.length()),ls);
                ls.remove(ls.size()-1);
            }
        }
    }
    static boolean check(String s)
    {
        String str="";
        for(int i=0;i<s.length();i++)
        {
            str=s.charAt(i)+str;
        }
        //System.out.println(str);
        if(str.equals(s))
            return true;
        else return false;
    }
}