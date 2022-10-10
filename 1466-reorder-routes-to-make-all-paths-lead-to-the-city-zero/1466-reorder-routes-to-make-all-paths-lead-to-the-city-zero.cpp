class Solution {
public:
    int minReorder(int n, vector<vector<int>>& con) {
         set<vector<int>> edges;
        for(auto x : con) edges.insert(x);   
        
        vector<vector<int>> g(n);
        for(auto x : con){
            int u = x[0], v = x[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        vector<bool> vis(n,false); vis[0] = true;
        queue<int> q; q.push(0);
        int cnt = 0;
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int v : g[u]){
                if(!vis[v]){
                    if(edges.find({v,u}) == edges.end()) cnt++;
                    q.push(v); vis[v] = true;
                }
            }
        }
        
        return cnt;
    }
};