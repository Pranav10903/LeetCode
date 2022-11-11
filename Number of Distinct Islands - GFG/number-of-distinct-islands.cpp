//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    public:

    void dfs(vector<pair<int,int>>&v,vector<vector<int>>& grid,vector<vector<int>>&vis , int r , int c, int rb, int cb){

        if(r < 0 || r >= grid.size() || c<0 || c>= grid[0].size() || grid[r][c] == 0 || vis[r][c] == 1){

            return;

        }

        vis[r][c] = 1;

        int i = r , j = c;

        v.push_back({r-rb , c-cb});

        dfs(v , grid , vis , i+1 , j , rb , cb);

        dfs(v , grid , vis , i-1 , j , rb , cb);

        dfs(v , grid , vis , i , j+1 , rb , cb);

        dfs(v , grid , vis , i , j-1 , rb , cb);

    }

    int countDistinctIslands(vector<vector<int>>& grid) {

        int n = grid.size() , m = grid[0].size();

        set<vector<pair<int,int>>>s;

        vector<vector<int>>vis(n , vector<int>(m,0));

        for(int i = 0;i<n;i++){

            for(int j = 0;j<m;j++){

                if(!vis[i][j] && grid[i][j]){

                    vector<pair<int,int>>v;

                    dfs(v , grid , vis , i , j , i , j);

                    s.insert(v);

                }

            }

        }

        return s.size();

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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends