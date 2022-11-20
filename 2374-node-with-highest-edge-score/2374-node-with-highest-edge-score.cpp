class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int N = edges.size();
        vector<int> adj[N];
        for(int i = 0;i<N;i++){
            adj[edges[i]].push_back(i);
        }
        long long int ans = INT_MIN, res = 0;
        for(int i=0;i<N;i++){
            long long int sum = 0;
            for(auto it : adj[i]){
                sum+=it;
            }
            if(ans<sum){
                ans = sum;
                res = i;
            }
        }
        return res;
    }
};