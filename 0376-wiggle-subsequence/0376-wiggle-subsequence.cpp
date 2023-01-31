class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int i,j;
        i = j = 1;
        for(int x = 1; x < n; x++){
            if(nums[x-1]>nums[x]){
                i = j + 1;
            }
            else if(nums[x-1]<nums[x]){
                j = i + 1;
            }
        }
        return max(i,j);
    }
};