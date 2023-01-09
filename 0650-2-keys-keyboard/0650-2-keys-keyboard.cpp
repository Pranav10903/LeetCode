class Solution {
public:
    int minSteps(int n) {
        vector<int> data(n+1, INT_MAX);
        data[0] = 0, data[1] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 2; i * j <= n; ++j) {
                int k = i * j;
                data[k] = min(data[k], data[i] + j);
            }
        }
        return data.back();
    }
};