class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int incl = 0;
        int excl = 0;
        vector<int>count(1e4+1,0);
        for(auto it:nums){
            count[it]++;
        }
        for(int i=0;i<=1e4;i++){
            int newinc = excl + count[i]*i;
            int newexc = max(excl,incl);
            excl = newexc;
            incl = newinc;
        }
        return max(excl,incl);
    }
};