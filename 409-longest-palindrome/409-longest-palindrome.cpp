class Solution {
public:
    int longestPalindrome(string s) {
    int s_len = s.size();
    int letters[58] = {0};
    int pair =0;
    for(int i = 0; i < s_len; i++){
        letters[s[i] - 65]++;
        if(letters[s[i] - 65] == 2){
            pair++;
            letters[s[i] - 65] =0;
        }
    }
    
    for (int i = 0; i < 58; i++){

        if (letters[i]  == 1)
            return pair*2+1;
    }
    return pair*2;
    }
};