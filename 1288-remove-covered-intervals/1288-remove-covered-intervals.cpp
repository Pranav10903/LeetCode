class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int cur[] = {-1,-1};
        int result=0;
        for(auto in : intervals){
            if(cur[0]<in[0] && cur[1]<in[1]){
                cur[0] = in[0];
                result++;
            }
            cur[1] = max(cur[1],in[1]); 
        }
        return result;
    }
};