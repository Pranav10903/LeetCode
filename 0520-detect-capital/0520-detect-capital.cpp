class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        int count = 0;
        for(auto it : word){
            if(isupper(it)){
                count++;
            }
        }
        if(count==1 && isupper(word[0])){
            return true;
        }
        if(count==0 || count==n){
            return true;
        }
        return false;
    }
};