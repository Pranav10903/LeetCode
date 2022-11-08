class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
         vector<pair<long long int,long long int>>adj[n];
        for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue< pair<long long int,long long int>, vector<pair<long long int,long long int>>, greater<pair<long long int,long long int>>> q;
        vector<long long> dist(n, 1e18);
        vector<int> paths(n , 0);
        q.push({0, 0});
        long long mod = (long long)(1e9 + 7);
        dist[0] = 0;
        paths[0] = 1;
        while(!q.empty()){
            long long int node = q.top().second;
            long long int dis = q.top().first;
            q.pop();
            for(auto it: adj[node]){
                long long int adjNode = it.first;
                long long int eW = it.second;
                if(dis+eW < dist[adjNode]){
                    dist[adjNode] = dis + eW;
                    q.push({ dist[adjNode],adjNode});
                    paths[adjNode] = paths[node];
                }
                else if(dist[adjNode]==dis+eW){
                    paths[adjNode] = (paths[adjNode] +paths[node])% mod;
                }
            }
        }
        return paths[n-1] % mod;
    }
};