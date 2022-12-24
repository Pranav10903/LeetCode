class Solution {
public:
    int numTilings(int N) {
        int mod = 1e9 + 7;
        vector<long long int> dp(1006,0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        if(N<=3){
            return dp[N];
        }
        for(int i=4;i<=N;i++){
            dp[i] = 2*dp[i-1]+dp[i-3];
            dp[i] %= mod;
        }
        return dp[N];
    }
};