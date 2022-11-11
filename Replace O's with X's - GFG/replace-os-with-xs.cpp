//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> grid)
    {
        // code here
        vector<vector<int>>vis(n , vector<int>(m , 0));
        vector<vector<char>>ans(n , vector<char>(m , 'X'));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 'O' && (i==0 || j==0 || i==n-1 || j==m-1))
                {
                    vis[i][j] = 1;
                    q.push({i,j});
                }
            }
        }
        
        int drow[] = {-1 , 0 , +1 , 0};
        int dcol[] = {0 , +1 , 0 , -1};
        
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow = row+drow[i];
                int ncol = col+dcol[i];
                if(ncol>=0 && nrow>=0 && nrow<n && ncol<m &&
                   grid[nrow][ncol]=='O' && vis[nrow][ncol] == 0)
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow , ncol});
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j] == 1)
                {
                    ans[i][j] = 'O';
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends