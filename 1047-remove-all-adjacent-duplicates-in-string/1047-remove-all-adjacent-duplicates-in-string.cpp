class Solution {
public:
    string removeDuplicates(string S) {
        string ans;  
        for(char i:S)  
        {
            if(ans.size()==0) ans.push_back(i);
            else if(i==ans.back()) ans.pop_back();
            else ans.push_back(i);
        }
        return ans;
    }
};