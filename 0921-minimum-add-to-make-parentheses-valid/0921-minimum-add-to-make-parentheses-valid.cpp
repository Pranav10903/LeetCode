class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        int open,close;
        open = close = 0;
        for(int i=0;i<n;i++){
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
        return open+close;
    }
};