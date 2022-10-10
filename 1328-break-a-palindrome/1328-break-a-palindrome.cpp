class Solution {
public:
    string breakPalindrome(string palindrome) {
        int size = palindrome.length();
        if(size==1) return "";
        for(int i=0;i<size;i++){
            if(palindrome[i]=='a' or i==size/2){
                continue;
            }
            else{               
                palindrome[i] = 'a';    
                return palindrome;
            }
        }
        palindrome[size-1] = 'b';
        return palindrome;
    }
};