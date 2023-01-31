class Solution {
public:
    int n,m;
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> pairs;
        n = ages.size();
        
        for(int i = 0; i < n; i++){
            pairs.push_back({ages[i], scores[i]});
        }
        sort(pairs.begin(), pairs.end());

        vector<int> next(n + 1), curr(n + 1);
        
        for(int i = n - 1; i >= 0; i--){
            for(int prev = i - 1; prev >= -1; prev--){
                int ans = next[prev + 1];

                if(prev == -1 || pairs[prev].second <= pairs[i].second){
                    ans = max(ans, pairs[i].second + next[i + 1]);
                }
                
                curr[prev + 1] = ans;
            }
            next = curr; 
        }
        return next[0];
    }
};