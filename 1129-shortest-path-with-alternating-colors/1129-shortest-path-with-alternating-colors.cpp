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
        // startnode, no of steps distance, color of edge
        q.push({0,0, -1});
        while(!q.empty()){
            auto iter = q.front();
            q.pop();
            int node = iter[0];
            int distance = iter[1];
            int prevC = iter[2];
            for(auto it : adj[node]){
                int neighbourNode = it.first;
                int curColor = it.second;
                if(curColor != prevC && vis[neighbourNode][curColor]==false){
                    vis[neighbourNode][curColor] = true;
                    q.push({neighbourNode, 1+distance, curColor});
                    if(dist[neighbourNode]==-1){
                        dist[neighbourNode] = 1 + distance;
                    }
                }
            }
            
        }
        return dist;
    }
};
/*
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,
                                         vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& redEdge : redEdges) {
            adj[redEdge[0]].push_back({redEdge[1], 0});
        }
        for (auto& blueEdge : blueEdges) {
            adj[blueEdge[0]].push_back(make_pair(blueEdge[1], 1));
        }

        vector<int> answer(n, -1);
        vector<vector<bool>> visit(n, vector<bool>(2));
        queue<vector<int>> q;

        // Start with node 0, with number of steps as 0 and undefined color -1.
        q.push({0, 0, -1});
        visit[0][1] = visit[0][0] = true;
        answer[0] = 0;

        while (!q.empty()) {
            auto element = q.front();
            int node = element[0], steps = element[1], prevColor = element[2];
            q.pop();

            for (auto& [neighbor, color] : adj[node]) {
                if (!visit[neighbor][color] && color != prevColor) {
                    visit[neighbor][color] = true;
                    q.push({neighbor, 1 + steps, color});
                    if (answer[neighbor] == -1) answer[neighbor] = 1 + steps;
                }
            }
        }
        return answer;
    }
};


*/