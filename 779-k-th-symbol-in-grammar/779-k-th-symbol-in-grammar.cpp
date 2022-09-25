class Solution {
public:
    void getVal(int n, int k, bool &x){
        if(n == 1 || k == 1){
            return;
        }
        
        int mid = pow(2,n-1)/2;
        if(k > mid){
            x = !x;
            return getVal(n-1, k-mid, x);
        }
        return getVal(n-1, k, x);
    }
    
    int kthGrammar(int n, int k) {
        bool x = false;
        getVal(n, k, x);
        return x;
    }
};