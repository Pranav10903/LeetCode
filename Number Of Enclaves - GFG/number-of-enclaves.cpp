//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int i,int j,vector<vector<int>>&grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()  || grid[i][j]!=1 ){
            return;
        }
        grid[i][j]=0;
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int r=grid.size();
        int c=grid[0].size();
        int count=0;
        for(int i=0;i<c;i++){
            if( grid[0][i]==1){
                dfs(0,i,grid);
            }
            if(grid[r-1][i]==1){
                dfs(r-1,i,grid);
            }
            
        }
        for(int i=0;i<r;i++){
            if( grid[i][0]==1){
                dfs(i,0,grid);
            }
            if(grid[i][c-1]==1){
                dfs(i,c-1,grid);
            }
            
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
        return count; 
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends