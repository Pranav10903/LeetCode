class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m));
        int res = INT_MIN;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 || j==m-1 || matrix[i][j]=='0'){
                    dp[i][j] = matrix[i][j]-'0';
                }
                else{
                    dp[i][j] = min({dp[i+1][j+1],dp[i+1][j],dp[i][j+1]}) + 1;
                }
                res = max(res,dp[i][j]);
            }
        }
        return res*res;
    }
};