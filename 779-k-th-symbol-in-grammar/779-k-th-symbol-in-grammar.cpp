class Solution {
public:
    void getVal(int n, int k, bool &x){
        if(n == 1 || k == 1){
            return;
        }
        
        int z = 1 << (n-1);
        if(k > z/2){
            x = !x;
            return getVal(n-1, k-z/2, x);
        }
        return getVal(n-1, k, x);
    }
    
    int kthGrammar(int n, int k) {
        bool x = false;
        getVal(n, k, x);
        return x;
    }
};