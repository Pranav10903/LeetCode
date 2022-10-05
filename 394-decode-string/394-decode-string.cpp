class Solution {
public:
    string decodeString(string s) {
        vector<pair<int,int>>st;
        string ans = "";
        int repeat = 0, i = 0;
        for(char c:s){
            if(isdigit(c)){
                if(!repeat){
                    repeat = c - '0';
                }
                else{
                    repeat = repeat*10 + c - '0';
                }
            }
            else if(c=='['){
                st.push_back({i,repeat-1});
                repeat = 0;
            }
            else if(c==']'){
                auto last = st.back();
                st.pop_back();
                int cur = i;
                for(int k=0;k<last.second;k++){
                    ans.append(ans,last.first,cur-last.first);
                    i+=cur-last.first;
                }
            }
            else{
                ans.push_back(c);
                i++;
            }
        }
        return ans;
    }
};