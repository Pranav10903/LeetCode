class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsofar = INT_MIN, maxtill = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            maxtill = maxtill + nums[i];
            if(maxsofar<maxtill){
                maxsofar = maxtill;
            }
            if(maxtill<0){
                maxtill = 0;
            }
        }
        return maxsofar;
    }
};