class Solution {
public:
        int calc(vector<int>& pr , int ind , bool buy , vector<vector<int>>& dp) {
        if(ind >= pr.size()) // If we have crossed the day , no trade possible return 0;
            return 0;
        
        if(dp[ind][buy] != -1)
            return dp[ind][buy]; // return if we have memoized the answer the before
        
        int tk , ntk;
        
        if(buy) {
            tk = -pr[ind] + calc(pr , ind + 1 , false , dp); // If we are buying , our net profit is minus buying price , and we will forward to next day.
            ntk = calc(pr , ind + 1 , true , dp); // If we are not buying , just move to next day
            
            return dp[ind][buy] = max(tk , ntk); // find max in buying case.
        }        
        
		// If we are selling.
        tk = pr[ind] + calc(pr , ind + 2 , true , dp); // If selling on day `i` , we will have a income of +pr[ind] and due to cooldown , next transaction will be done on `i + 2` day.
        ntk = calc(pr , ind + 1 , false , dp); // If we are not selling on that day , move to next day.
        
        return dp[ind][buy] = max(tk , ntk); // find max in selling case
    }
    
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size() , vector<int>(2 , -1));
        return calc(prices , 0 , true , dp);
    }

};