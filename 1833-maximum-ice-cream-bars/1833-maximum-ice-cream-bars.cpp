class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int m = *max_element(costs.begin(),costs.end());
        int n = costs.size();
        int ans = 0;
        vector<int> mp(m+1,0);
        for(int i=0;i<n;i++){
            mp[costs[i]]++;
        }
        for(int i=1;i<=m;i++){
            if(mp[i]==0){
                continue;
            }
            if(coins < i){
                break;
            }
            int count = min(mp[i],coins/i);
            coins = coins - i*count;
            ans += count;
        }
        return ans;
    }    
};