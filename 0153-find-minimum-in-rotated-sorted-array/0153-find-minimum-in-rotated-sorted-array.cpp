class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, high = nums.size()-1;
        while(lo<high){
            int mid = lo+(high-lo)/2;
            if(nums[mid]<nums[high]){
                high = mid;
            }
            else{
                lo = mid+1;
            }
        }
        return nums[lo];
    }
};