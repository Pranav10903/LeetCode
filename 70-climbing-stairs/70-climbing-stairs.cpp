class Solution {
public: 
    unordered_map<int,int>cache;
    int climbStairs(int n) {
            if(cache.find(n)!=cache.end()){
                return cache[n];
            }
            int result = 0;
            if(n==0) return 0;
            else if(n==1) return 1;
            else if(n==2) return 2;
            else result = climbStairs(n-1) + climbStairs(n-2);
            return cache[n] = result;
    }
};