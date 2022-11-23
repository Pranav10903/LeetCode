class Solution {
    public static boolean isIsland;
    public static void dfs(int [][] grid, boolean [][] visited, int x, int y) {
        // check if the (x,y) point is valid or not
        if(x>=0 && x<grid.length && y>=0 && y<grid[0].length && grid[x][y]==0 && !visited[x][y]) {
            // if point (x,y) is land and at the edge means not covered by water 
            // it is not island. make the global variable false
            if(x==0 || x==grid.length-1 || y==0 || y==grid[0].length-1) isIsland =  false;
            visited[x][y] = true;
            dfs(grid,visited,x+1,y);
            dfs(grid,visited,x-1,y); 
            dfs(grid,visited,x,y+1);
            dfs(grid,visited,x,y-1);
        }
    }

    public int closedIsland(int[][] grid) {
        int count = 0;
        boolean [][] visited = new boolean[grid.length][grid[0].length];
        for(int i=0;i<grid.length;i++) {
            for(int j=0;j<grid[0].length;j++) {
                // do DFS check for all unvisited land
                if(grid[i][j]==0 && !visited[i][j]) {
                    isIsland = true;
                    dfs(grid, visited, i,j);
                    // if dfs could not find any violation means cornor row/column
                    // then increment final island number by 1
                    if(isIsland) count++;
                }
            }
        }
        return count;
    }
}