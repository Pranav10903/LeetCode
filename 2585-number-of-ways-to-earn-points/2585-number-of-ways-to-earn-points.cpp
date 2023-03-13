class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        vector<int> dp(target + 1);
        dp[0] = 1;
        int MOD = (int) 1e9 + 7;
        for(auto it : types){
            for(int i = target; i > 0; --i){
                for(int k = 1; k <= it[0] && i - it[1] * k >= 0; ++k){
                    dp[i] = (dp[i] + dp[i - it[1] * k]) % MOD;
                }
            }
        }
        return dp[target];
    }
};