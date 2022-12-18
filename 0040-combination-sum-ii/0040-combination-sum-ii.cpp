class Solution {
public:
    void recur(int index, vector<vector<int>> &ans, vector<int> &ds, int target, vector<int> &candidates){
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        for(int i = index; i < candidates.size();i++){
            if(i > index and candidates[i-1]==candidates[i]) continue;
            if(candidates[i]>target) break;
            ds.push_back(candidates[i]);
            recur(i+1,ans,ds,target-candidates[i],candidates);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> ds;
        vector<vector<int>> ans;
        recur(0,ans,ds,target,candidates);
        return ans;
    }
};