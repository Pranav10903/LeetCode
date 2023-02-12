class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : redEdges){
            adj[it[0]].push_back({it[1],0});
        }
        for(auto it : blueEdges){
            adj[it[0]].push_back({it[1],1});
        }
        vector<int> dist(n, -1);
        vector<vector<bool>> vis(n, vector<bool>(2));
        dist[0] = 0;
        queue<vector<int>>q;
        vis[0][1] = vis[0][0] = true;
        q.push({0,0, -1});
        while(!q.empty()){
            auto iter = q.front();
            q.pop();
            int node = iter[0];
            int distance = iter[1];
            int prevC = iter[2];
            for(auto it : adj[node]){
                if(it.second != prevC && vis[it.first][it.second]==false){
                    vis[it.first][it.second] = true;
                    q.push({it.first, 1+distance, it.second});
                    if(dist[it.first]==-1){
                        dist[it.first] = 1 + distance;
                    }
                }
            }
            
        }
        return dist;
    }
};