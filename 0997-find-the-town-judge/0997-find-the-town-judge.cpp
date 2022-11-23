class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n+1),outdegree(n+1);
        int ans = -1;
        if(n==1) return 1;
        for(auto it : trust){
            int truster = it[0];
            int trustee = it[1];
            outdegree[truster]++;
            indegree[trustee]++;
        }
        for(int i=0;i<=n;i++){
            if(indegree[i]==n-1 && outdegree[i]==0){
                ans = i;
                break;
            }
        }
        return ans;
    }
};