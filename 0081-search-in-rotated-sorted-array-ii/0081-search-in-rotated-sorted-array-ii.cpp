class Solution {
public:
    bool find(vector<int> &nums, int i, int j, int target){
        if(i>j){
            return false;
        }
        int mid = i + (j-i)/2;
        if(nums[mid] == target){
            return true;
        }
        if((nums[mid]<=nums[i] && nums[mid]<=nums[j])){
            return find(nums,i,mid-1,target) || find(nums,mid+1,j,target);
        }
        if(nums[i]<=target && nums[mid]>=target){
            return find(nums, i, mid-1, target);
        }
        return find(nums, mid+1, j, target);
    }
    bool search(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size()-1;
        return find(nums,i,j,target);
    }
};