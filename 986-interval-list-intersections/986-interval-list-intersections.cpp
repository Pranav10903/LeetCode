class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>>ret;
        int n = firstList.size();
        int m = secondList.size();
        int ptr1 = 0 , ptr2 = 0;
        while(ptr1 < n && ptr2 < m){
            int ll = firstList[ptr1][0] , lr = firstList[ptr1][1];
            int rl = secondList[ptr2][0] , rr = secondList[ptr2][1];
            if(ll >= rl && ll <= rr){
                vector<int>v = {ll , min(rr , lr)};
                ret.push_back(v);
            }else if(rl >= ll && rl <= lr){
                vector<int>v = {rl , min(rr , lr)};
                ret.push_back(v);
            }else if(lr >= rl && lr <= rr){
                vector<int>v = {max(ll , rl), lr};
            }else if(rr >= ll && rr <= lr){
                vector<int>v = {max(ll , rl) , rr};
            }
            if(ptr1 + 1 == n && ptr2 + 1 == m )break;
            if(ptr2 + 1 == m)++ptr1;
            else if(ptr1 + 1 == n)++ptr2;
            else if(firstList[ptr1 + 1][0] <= secondList[ptr2 + 1][0]){
                ++ptr1;
            }else{
                ++ptr2;
            }
        }
        return ret;
    }
};