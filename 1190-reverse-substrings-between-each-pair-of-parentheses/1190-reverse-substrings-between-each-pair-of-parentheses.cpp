class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>st;
        string ans = "";
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if (s[i] == ')'){
                reverse(s.begin()+st.top()+1,s.begin()+i);
                st.pop();
            }
        }
       for(int i=0;i<s.length();i++){
           if(s[i]!='(' and s[i]!=')'){
               ans = ans+s[i];
           }
       }
        return ans;
    }
};