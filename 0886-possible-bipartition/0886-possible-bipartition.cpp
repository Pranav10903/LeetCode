class UnionFind{
    public:
    vector<int> parent,rank;
    UnionFind(int size){
        parent.resize(size);
        rank.resize(size,0);
        for(int i=0;i<size;i++){
            parent[i] = i;
        }
    }
    int find(int node){
        if(parent[node]==node){
            return parent[node];
        }
        return parent[node] = find(parent[node]);
    }
    void union_set(int u,int v){
        int uset = find(u);
        int vset = find(v);
        if(uset==vset){
            return;
        }
        else if(rank[uset]<rank[vset]){
            parent[uset] = vset;
        }
        else if(rank[uset]>rank[vset]){
            parent[vset] = uset;
        }
        else{
            parent[vset] = uset;
            rank[uset]++;
        }
    }
};

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(auto it : dislikes){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        UnionFind dsu(n+1);
        for(int i=0;i<=n;i++){
            for(auto it : adj[i]){
                if(dsu.find(i)==dsu.find(it)){
                    return false;
                }
                dsu.union_set(adj[i][0],it);
            }
        }
        return true;
    }
};