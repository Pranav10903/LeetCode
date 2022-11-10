class Solution {
int digitSum(int n){
        return !n ? 0 : n%10 + digitSum(n/10);
    }
public:
    int getLucky(string s, int k,int sum = 0) {
        for(char&_s: s) sum += digitSum(_s-'a'+1);
        while((k--)>1) sum = digitSum(sum);
        return sum;
    }
};