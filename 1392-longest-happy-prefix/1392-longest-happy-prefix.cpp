class Solution {
public:
    vector<int> prefix_function(string s){
        int n=s.size();
        vector<int> pi(n,0);
        for(int i=1;i<n;++i){
            int j = pi[i-1];

            while(j>0 && s[i]!=s[j]) 
                j=pi[j-1];

            if(s[i]==s[j])
                 ++j;

            pi[i]=j;
        }
        return pi;
    }
    
    string longestPrefix(string s) {
        vector<int> prefix = prefix_function(s);
        string str="";
        int n=s.size();
        str = s.substr(0,prefix[n-1]);
        return str;
    }
};