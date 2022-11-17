class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        int len = 0;
        for(int i=0;i<size;i++){
            if(len==0||nums[len-1]<nums[i]){
                nums[len++] = nums[i];
            }
            else{
                *lower_bound(begin(nums),begin(nums)+len,nums[i]) = nums[i];
            }
        }
            return len;
    }
};