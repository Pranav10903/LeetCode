class Solution {
private:
    vector<int>parent;
    int find(int node){
        return parent[node] == -1 ? node : parent[node] = find(parent[node]);
    }
    void setUnion(int a,int b){
        int x = find(a),y = find(b);
        if(x!=y){
            parent[x] = y;
        }
    }
public:
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26,-1);
        for(auto it : equations){
            if(it[1]=='='){
                setUnion(it[0]-'a',it[3]-'a');
            }
        }
        for(auto it : equations){
            if(it[1]=='!' and find(it[0]-'a')==find(it[3]-'a')){
                return  false;
            }
        }
        return true;
    }
};