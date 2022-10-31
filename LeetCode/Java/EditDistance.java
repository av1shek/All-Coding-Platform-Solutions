class Solution {
    public int minDistance(String s1,String s2) {
        int dp[][]=new int[s1.length()][s2.length()];
        return find(s1,s2,s1.length()-1,s2.length()-1,dp);
    }
 static int find(String s1,String s2,int l1,int l2,int dp[][])
    {
        if(l1<0)
            return l2+1;
        if(l2<0)
            return l1+1;
        if(dp[l1][l2]>0)
            return dp[l1][l2];
        if(s1.charAt(l1)==s2.charAt(l2))
            return dp[l1][l2]=find(s1,s2,l1-1,l2-1,dp);
        else
        {
            int x,y,z;
            x=find(s1,s2,l1,l2-1,dp);//insert
            y=find(s1,s2,l1-1,l2,dp);//delete
            z=find(s1,s2,l1-1,l2-1,dp);//replace
            dp[l1][l2]=1+Math.min(x,Math.min(y,z));
        }
        return dp[l1][l2];
    }
}