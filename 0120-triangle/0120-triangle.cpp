class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<vector<int>> &triangle, int i, int j,int n){
        if(i==n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans = triangle[i][j];
        int le = solve(triangle,i+1,j,n);
        int ri = solve(triangle,i+1,j+1,n);
        ans += min(le,ri);
        return dp[i][j]=ans;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for(int i=0;i<n;i++){
            vector<int>temp(n,-1);
            dp.push_back(temp);
        }
        return solve(triangle,0,0,n);
    }
};