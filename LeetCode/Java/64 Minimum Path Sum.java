class Solution {    
    public void print(int[][] grid){
        for(int i=0;i<grid.length;i++){
            for(int j =0;j<grid[i].length;j++){
                System.out.print(grid[i][j]+" ");
            }
            System.out.println();
        }
        System.out.println();        
    }
    public int minPathSum(int[][] grid) {        
        int dp[][] = new int[grid.length][grid[0].length];
        dp[0][0]= grid[0][0];
        // horizontal 
        for(int i =1;i<grid[0].length;i++){
            dp[0][i] = dp[0][i-1] + grid[0][i]; 
        }        
        for(int i =1;i<grid.length;i++){
            dp[i][0] = dp[i-1][0] + grid[i][0]; 
        }        
        for(int i =1;i<grid.length;i++){
            for(int j =1 ; j<grid[i].length;j++){
                dp[i][j] = grid[i][j]+ Math.min(dp[i-1][j],dp[i][j-1]);
            }
        }       
        
        return dp[grid.length-1][grid[0].length-1];
    }
}