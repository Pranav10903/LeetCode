class Solution {
public:
    int MOD = 1e9 + 7;
    int pow2(int x, int y){
        if(y == 0) return 1;
        if(y == 1) return x;
        long ans = 1;
        if(y%2 == 0){
            ans  = pow2(x, y/2);
            ans  =  ans * ans;
        }
        else{
            ans = pow2(x, y-1);
            ans =  ans * x;
        }
        return ans % MOD;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int answer = 0;
        while(low<=high){
            if(nums[low] + nums[high] <= target){
                answer += pow2(2, high - low);
                answer = answer % MOD;
                low++;
            }
            else{
                high--;
            }
        }
        return answer%MOD;
    }
};