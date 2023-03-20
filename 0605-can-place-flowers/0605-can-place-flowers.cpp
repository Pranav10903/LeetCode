class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        vector<int> fb;
        fb.push_back(0);
        for(auto it : flowerbed){
            fb.push_back(it);
        }
        fb.push_back(0);
        for(int i = 1; i < fb.size()-1; i++){
            if(fb[i] == 0 && fb[i+1] == 0 && fb[i-1] == 0){
                fb[i] = 1;
                n = n-1;
            }
        }
        return (n<=0);
    }
};