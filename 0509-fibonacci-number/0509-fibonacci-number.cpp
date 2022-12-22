class Solution {
public:
        int fib(int N) {
            if(N<2){
                return N;
            }
            vector<int> fibo(N+1);
            fibo[0] = 0;
            fibo[1] = 1;
            for(int i=2;i<=N;i++){
                fibo[i] = fibo[i-1] + fibo[i-2];
            }
            return fibo[N];
        }
};