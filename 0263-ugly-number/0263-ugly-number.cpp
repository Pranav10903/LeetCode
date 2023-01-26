class Solution {
public:
    bool isUgly(int n) {
        if(n<=0) return 0;
        while(n%3==0) n = n/3;
        while(n%5==0) n = n/5;
        return (n & (n-1) )== 0;
    }
};