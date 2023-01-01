class Solution {
public:
    string countAndSay(int n) {
        if(n==0) {
            return "";
        }
        string val = "1";
        while(--n){
            string s = "";
            for(int i=0;i<val.length();i++){
                int count = 1;
                while(i+1 < val.length() and (val[i]==val[i+1])){
                    count++;
                    i++;
                }
                s += to_string(count) + val[i];
            }
            val = s;
        }
        return val;
    }
};