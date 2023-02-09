class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string>mp;
        vector<vector<long long>> freq(26, vector<long long>(26,0));
        for(auto it : ideas){
            mp.insert(it);
        }
        for(auto it : ideas){
            string nidea = it;
            for(char chari = 'a'; chari<='z';chari++){
                nidea[0] = chari;
                if(mp.find(nidea)==mp.end()){
                    freq[it[0] - 'a'][chari - 'a']++;
                }
            }
        }
        long long ans = 0ll;
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < i ; j++){
                ans = ans + freq[i][j] * freq[j][i] * 2ll;
            }
        }
        return ans;
    }
};