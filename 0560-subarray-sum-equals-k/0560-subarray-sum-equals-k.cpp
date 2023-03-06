class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int res = 0;
        unordered_map<int,int> mp;
        mp[0]++;
        for(int i = 0; i<nums.size(); i++){
            sum+=nums[i];
            if(mp.find(sum-k)!=mp.end()){
                res += mp[sum - k];
            }
            mp[sum]++;
        }
        return res;
    }
};