class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n  = nums.size();
        int sum = 0, leftsum = 0;
        for(auto it: nums){
            sum+=it;
        }
        for(int i=0;i<n;i++){
            if(leftsum == sum-nums[i]-leftsum){
                return i;
            }
            leftsum += nums[i];
        }
        return -1;
    }
};