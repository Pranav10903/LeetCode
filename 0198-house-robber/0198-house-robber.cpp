class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1 = 0;
        int prev2 = 0;
        for(auto it : nums){
            int temp = prev1;
            prev1 = max(prev1,it+prev2);
            prev2 = temp;
        }
        return prev1;
    }
};