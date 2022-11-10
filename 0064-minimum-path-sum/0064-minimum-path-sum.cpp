class Solution {
public:
    int dp[201][201];
    int dfs(int i,int j,int n,int m,vector<vector<int>>&grid){ 
        //base
        if(i==n-1 and j==m-1){
            return grid[i][j];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int right = INT_MAX;
        int down = INT_MAX;
        //go right
        if(i<n-1){
            cout<<1;
            right = grid[i][j] + dfs(i+1,j,n,m,grid);
        }
        
        //go down
        if(j<m-1){
            cout<<2;
            down = grid[i][j] + dfs(i,j+1,n,m,grid);
        }
        
        return dp[i][j] = min(right,down);
        
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return dfs(0,0,n,m,grid);
    }
};