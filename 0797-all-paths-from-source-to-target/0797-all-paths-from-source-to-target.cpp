class Solution {
public:
    int target;
    vector<vector<int>> res;
    vector<int> temp;
    void dfs(int curNode,vector<vector<int>>& graph){
        temp.push_back(curNode);
        if(curNode==target){
            res.push_back(temp);
        }
        else{
            for(auto it : graph[curNode]){
                dfs(it,graph);
            }
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        target = graph.size()-1;
        dfs(0,graph);
        return res;
    }
};