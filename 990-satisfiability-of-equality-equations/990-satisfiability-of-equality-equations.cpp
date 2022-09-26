class Solution {
private:
    vector<int> parent;
    int find(int node){
        return parent[node] == -1 ? node : parent[node] = find(parent[node]);
    }
    void setUnion(int a, int b){
        int x = find(a), y = find(b);
        if(x != y) parent[x] = y;
    }
public:
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26, -1);
        for(auto eq : equations){
            if(eq[1] == '=') setUnion(eq[0] - 'a', eq[3] - 'a');
        }
        for(auto eq : equations){
            if(eq[1] == '!' && find(eq[0] - 'a') == find(eq[3] - 'a')) return false;
        }
        return true;
    }
};