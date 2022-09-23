class Solution {
public:
    bool isSubs(string &s,string &t,int s_size,int t_size)
    {
        if(s_size==0)
        {
            return true;
        }
        if(t_size==0)
        {
            return false;
        }
        if(s[s_size-1]==t[t_size-1]){
            return isSubs(s,t,s_size-1,t_size-1);
        }
        else
            return isSubs(s,t,s_size,t_size-1);
    }
    bool isSubsequence(string s, string t) {
        if(isSubs(s,t,s.length(),t.length()))
        {
            return true;
        }
        return false;
    }
};