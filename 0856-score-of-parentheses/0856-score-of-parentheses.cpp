class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0,two=1;
        for(int ind = 0;ind<s.size();ind++){
            if(s[ind]=='('){
                two+=two;
            }
            else{
                two/=2;
                if(s[ind-1]=='('){
                    ans+=two;
                }
            }
        }
        return ans;
    }
};