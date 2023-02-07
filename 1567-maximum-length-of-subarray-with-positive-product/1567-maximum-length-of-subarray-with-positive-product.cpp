class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int pos = 0, neg = 0, ans = 0;
        for(auto it : nums){
            if(it==0){
                pos = 0;
                neg = 0;
            }
            else if(it>0){
                pos = pos + 1;
                neg = (neg==0) ? 0 : neg + 1;
            }
            else{
                int val = pos;
                pos = (neg==0) ? 0 : neg + 1; // even case
                neg = val + 1;
            }
            ans = max(ans,pos);
        }
        return ans;
    }
};