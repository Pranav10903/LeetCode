class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int i,j,res;
        i = j = res = 0;
        while(j<fruits.size()){
            mp[fruits[j]]++;
            if(mp.size()<=2){
                res = max(res,j-i+1);
            }
            else{
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0){
                    mp.erase(fruits[i]);
                }
                i++;
            }
            j++;
        }
        return res;
    }
};