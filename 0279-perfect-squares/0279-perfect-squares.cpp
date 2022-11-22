class Solution {
public:
     int numSquares(int n) {
        vector<int> arr;
        for (int i = 1; (i*i) <= n; ++i){
            int sq = i * i;
            if (sq <= n) arr.push_back(sq);
        }

        
        return bfs(arr, n);
    }

    int bfs(vector<int> &nums, int target){
        queue<int> q;
        q.push(target);
        unordered_set<int> seen;
        seen.insert(target);
        int d = 0;
        
        while(!q.empty()){
            int n = q.size();
            for (int i = 0; i < n; ++i){
                int node = q.front();
                q.pop();

                if (node == 0) return d;
                for (int num: nums){
                    int newNum = node - num;
                    if (newNum < 0 || seen.count(newNum)) continue;
                    if (newNum == 0) return d + 1;
                    seen.insert(newNum);
                    q.push(newNum);
                }
            }
            ++d;
        }
        return d;
    }
};