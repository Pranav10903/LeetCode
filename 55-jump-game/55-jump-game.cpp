class Solution {
public:
    bool canJump(vector<int>& nums) {
        int count = 0,reach = 0;
        int n = nums.size(),i=0;
        for(i=0;i<n and i<=reach;i++){
            if(i+nums[i]>reach){
                count++;
                reach = i+nums[i];
            }
        }
        return i==n;
    }
};