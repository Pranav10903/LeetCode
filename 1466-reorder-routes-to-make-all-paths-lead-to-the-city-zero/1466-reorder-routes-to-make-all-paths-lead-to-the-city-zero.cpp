class Solution {
public:
    int ans = 0;
    int minReorder(int n, vector<vector<int>>& arr) {
        vector<int>neighbour[n],adj[n];
        for(auto it:arr){
            neighbour[it[0]].push_back(it[1]);
            neighbour[it[1]].push_back(it[0]);
            adj[it[0]].push_back(it[1]);
        }
        queue<int>q;
        vector<int>vis(n,0);
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            vis[node] = 1;
            q.pop();
            for(auto Neighbour:neighbour[node]){
                if(!vis[Neighbour]){
                    bool canReach = false;
                    for(auto AdjacenttoNeighbour:adj[Neighbour]){
                        if(AdjacenttoNeighbour == node){
                            canReach = true;
                            q.push(Neighbour);
                            break;
                        }
                    }
                    if(!canReach) {
                        ans++;
                        q.push(Neighbour);
                    }
                }
            }
        }
        return ans;
    }
};