class Solution {
public:
    bool isPal(string s, int start, int end){
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void dfs(int ind, string s, vector<string>&cur, vector<vector<string>> &res){
        if(ind >= s.length()){
            res.push_back(cur);
        }
        for(int i = ind; i < s.length(); i++){
            if(isPal(s,ind,i)){
                cur.push_back(s.substr(ind,i-ind+1));
                dfs(i+1, s, cur, res);
                cur.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string> cur;
        dfs(0,s,cur,res);
        return res;
    }
    
};