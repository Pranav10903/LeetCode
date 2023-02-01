class Solution {
public:
    int count = 0;
    int countArrangement(int n) {
        vector<int> vis(n+1,0);
        solve(n,1,vis);
        return count;
    }
    void solve(int n, int it, vector<int> vis){
        if(it>n) {
            count++;
        }
        for(int i = 1; i <= n; i++){
            if(!vis[i] && (it%i==0 || i%it==0)){
                vis[i] = 1;
                solve(n,it+1,vis);
                vis[i] = 0;
            }
        }
    }
};