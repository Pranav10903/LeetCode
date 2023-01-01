class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int close = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]==')'){
                if(open==0){
                    close++;
                }
                else{
                    open--;
                }
            }
            else{
                open++;
            }
        }
        return open + close;
    }
};