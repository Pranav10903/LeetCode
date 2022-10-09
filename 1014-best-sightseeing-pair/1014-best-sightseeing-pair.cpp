class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int i = values[0]; int ans = INT_MIN;
        for(int j=1;j<values.size();j++){
            ans = max(ans,i+values[j]-j);
            i = max(i,values[j]+j);
        }
        return ans;
    }
};