class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector <int> sum(n+1);
        for(int i=1;i<=n;i++){
            sum[i] = sum[i-1]+nums[i-1];
        }
        set<int>st;
        for(int i=2;i<=n;i++){
            st.insert(sum[i-2]%k);
            if(st.find(sum[i]%k)!= st.end()){
                return true;
            }
        }
        return false;
    }
};