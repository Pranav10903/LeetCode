class Solution {
public:
    int edgeScore(vector<int>& edges) {
        // int N = edges.size();
        // vector<int> adj[N];
        // for(int i = 0;i<N;i++){
        //     adj[edges[i]].push_back(i);
        // }
        // long long int ans = INT_MIN, res = 0;
        // for(int i=0;i<N;i++){
        //     long long int sum = 0;
        //     for(auto it : adj[i]){
        //         sum+=it;
        //     }
        //     if(ans<sum){
        //         ans = sum;
        //         res = i;
        //     }
        // }
        // return res;
         unordered_map<int,long long> mp;
        for(int i=0;i<edges.size();i++){
            mp[edges[i]] += i;
        }
        int ans = INT_MAX;
        long long mx = INT_MIN;
        for(auto &x : mp){
            mx = max(mx,x.second);
        }
        
        for(auto &x : mp){
            if(x.second == mx) ans = min(ans,x.first);
        }
        
        return ans;
    }
};