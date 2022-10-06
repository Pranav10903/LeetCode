class Solution {
public:
    static bool cmp(const pair<string, int> &p1, const pair<string, int> &p2) {
        if(p1.second != p2.second) 
            return p1.second > p2.second;
        else 
            return p1.first < p2.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(auto i : words) ++mp[i];
        vector<pair<string, int> > tmp;
        vector<string> ans;
        for(auto i : mp) tmp.emplace_back(i);
        sort(tmp.begin(), tmp.end(), cmp);
        for(int i = 0; i < k; ++i) ans.emplace_back(tmp[i].first);
        return ans;
    }
};
