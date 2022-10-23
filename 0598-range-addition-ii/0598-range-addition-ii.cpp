class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
         int xMin = m ;
        int yMin = n ;
        for(auto& op:ops)
        {
            xMin = min(op[0] , xMin) ;
            yMin = min(op[1] , yMin) ;
        }
        return xMin*yMin;
    }
};