class Solution {
public:
    int longestSubsequence(string s, int k) {
        int res = 0, cost = 1, n = s.size();
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0' || cost <= k) {
                k -= cost * (s[i] - '0');
                res++;
            }
            if (cost <= k)
                cost *= 2;
        }
        return res;
    }
};