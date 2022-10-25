class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n = word1.size();
        int m = word2.size();
        string s1 = "";
        string s2 = "";
        for(int i=0;i<n;i++){
            string vs = word1[i];
            s1 = s1+vs;
        }
        for(int i=0;i<m;i++){
            string vs1 = word2[i];
            s2 = s2+vs1;
        }
        return (s1==s2);       
    }
};