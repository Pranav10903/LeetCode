class Solution {
public:
    int concatenatedBinary(int n) {
        long ans=0;
        int noOfBits,mod=1e9+7;
        for(int i=1;i<=n;i++){
            noOfBits=log2(i)+1;
            ans=ans*(1 << noOfBits)+i;
            ans%=mod;
        }
        return ans;

    }
};