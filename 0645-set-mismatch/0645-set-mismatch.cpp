class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int esum = n*(n+1)/2;
        set<int>st;
        int asum = 0, dup = 0;
        for(int i=0;i<n;i++){
            asum+=nums[i];
            if(st.find(nums[i])!=st.end()){
                dup = nums[i];
            }
            st.insert(nums[i]);
        }
        int difference = esum - asum;
        int rep = difference+dup;
        return {dup,rep};
    }
};