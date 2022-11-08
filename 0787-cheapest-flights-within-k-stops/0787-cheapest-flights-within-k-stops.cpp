class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k){
        vector<pair<int,int>>adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(n, 1e9);
        queue<pair<int, pair<int,int>>> q;
        q.push({0,{src,0}});
        dist[src] = 0;
        //{stops , {node , distance}}
        while(!q.empty()){
            int node = q.front().second.first;
            int distance = q.front().second.second;
            int stops = q.front().first;
            q.pop();
            for(auto iter : adj[node]){
                int eW = iter.second;
                int adjN = iter.first;
                if(distance + eW < dist[adjN] and stops<=k){
                    dist[adjN] = distance + eW;
                    q.push({stops + 1,{adjN, dist[adjN]}});
                }
            }
        }
        if(dist[dst]==1e9){
            return -1;
        }
        return dist[dst];
    }
};