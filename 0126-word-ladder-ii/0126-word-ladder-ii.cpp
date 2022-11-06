class Solution {
unordered_map<string, int> map;
    vector<vector<string>> ans;
    string begin = "";
    
    void dfs(string &word, vector<string> &seq){
        if(word == begin){
            vector<string> tmp = seq;
            reverse(tmp.begin(), tmp.end());
            ans.push_back(tmp);
            return;
        }
        
        int steps = map[word];
        for(int i = 0; i < word.length(); i++){
            char original = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++){
                word[i] = ch;
                if(map.find(word) != map.end() && map[word]+1 == steps){
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
        
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set;
        queue<pair<string, int>> q;
        vector<string> seq;
        
        q.push({beginWord, 1});
        begin = beginWord;
        map[beginWord]  = 1;
        seq.push_back(endWord);
        
        for(auto x : wordList)
            set.insert(x);
        set.erase(beginWord);
        
        while(!q.empty()){
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            
            if(word == endWord){
                break;
            }
            
            for(int i = 0; i < word.length(); i++){
               char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(set.find(word) != set.end()){
                        q.push({word, step+1});
                        set.erase(word);
                        map[word] = step+1;
                    }
                }
                word[i] = original;
            }
        }
        dfs(endWord, seq);
        return ans;
        
    }
};