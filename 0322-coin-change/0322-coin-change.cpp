class Solution {
public:
    int coinChange(vector<int>& coins,int amount){
        int dp[amount+1];
        dp[0] = 0;
        sort(coins.begin(),coins.end());
        for(int i=1;i<=amount;i++){
            dp[i] = INT_MAX;
            for(auto it : coins){
                if(i-it<0) break;
                if(dp[i-it]!=INT_MAX){
                    dp[i] = min(dp[i],dp[i-it]+1);
                }
            }
        }
        return (dp[amount]==INT_MAX) ? -1 : dp[amount];
    }
};