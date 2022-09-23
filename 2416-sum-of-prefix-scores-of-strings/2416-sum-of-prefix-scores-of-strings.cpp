class Solution {
public:
    struct Trie{
        map<char, Trie*> mp;
        int cnt;
    };
    
    vector<int> sumPrefixScores(vector<string>& words) {
	
		// creating the root
        Trie *root = new Trie();
		
		// building the Trie
        for (auto w: words)
        {
            auto cur = root;
            for (auto i: w)
            {
                if (cur->mp.find(i) == cur->mp.end())
                    cur->mp[i] = new Trie();
                cur = cur->mp[i];
                cur->cnt += 1;
            }
        }
		
        vector<int> ans;
		
		// getting score of each word
        for (auto w: words)
        {
            auto cur = root;
            int val = 0;
            for (auto i: w)
            {
                cur = cur->mp[i];
                val += cur->cnt;
            }
            ans.push_back(val);
        }
        return ans;
    }
};