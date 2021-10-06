class Solution {
    
    
    public boolean isNotSafe(int[][] grid , int i , int j , boolean [][] visited){
    if(i<0 || i>=grid.length || j<0 || j>=grid[i].length || grid[i][j] != 1 || visited[i][j])
        return true;
        return false;
    }
    
    public int DFS(int[][] grid , int i , int j , boolean[][] visited){
        if(isNotSafe(grid, i, j , visited))
            return 0;
        visited[i][j] = true;
        
        return 1 + DFS(grid, i , j+1 ,visited)
                 + DFS(grid, i+1 , j ,visited)
                 + DFS(grid, i , j-1 ,visited)
                 + DFS(grid, i-1 , j ,visited);
        
    }
    public int maxAreaOfIsland(int[][] grid) {
        boolean [][] visited = new boolean [grid.length][grid[0].length];
        int max = 0;
        for(int i =0;i<grid.length;i++){
            for(int j =0;j<grid[i].length;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    max = Math.max(max, DFS(grid, i , j ,visited));
                }
            }
        }
        return max;
    }
}