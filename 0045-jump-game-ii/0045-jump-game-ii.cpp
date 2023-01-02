class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size() - 1, currentPosition = -1, nextPosition = 0, ans = 0;
        for (int index = 0; nextPosition < size; index++) {
            if (index > currentPosition){
                ans++;
                currentPosition = nextPosition;
            }
            nextPosition = max(nextPosition, nums[index] + index);
        }
        return ans;
    }
};