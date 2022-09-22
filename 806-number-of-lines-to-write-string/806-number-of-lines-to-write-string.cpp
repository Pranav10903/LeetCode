class Solution {
public:
    vector<int> numberOfLines(vector<int>& w, string s) {
        int line = 1, width = 0;
        for(auto c:s){
            if(width + w[c-'a'] >100){
                line++;
                width = w[c-'a'];
            }
            else{
                width += w[c-'a'];
            }
        }
        return {line,width};
    }
};