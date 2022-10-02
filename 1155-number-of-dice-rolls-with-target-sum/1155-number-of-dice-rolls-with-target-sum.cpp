class Solution {
public:
    int mod = 1e9+7;
    int ways(int i,int &n,int &k,int target,vector<vector<int>>& dp){
        if(target<0){
            return 0;
        }
        else if(i==n){
            if(target==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        else if(dp[i][target]!=-1){
            return dp[i][target];
        }
        else{
            dp[i][target] = 0;
            for(int j = 1; j<=k; j++){
                dp[i][target]+=ways(i+1,n,k,target-j,dp);
                dp[i][target]%=mod;
            }
            return dp[i][target];
        }
    }
    int numRollsToTarget(int n, int k, int target) {
        ios_base::sync_with_stdio(0);
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        int ans = ways(0,n,k,target,dp);
        return ans;
    }
};