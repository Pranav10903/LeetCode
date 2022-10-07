class Solution {
public:
    int dp[2002][2002];
    bool solve(int i, int k, vector<int>& arr)
    {
        int n = arr.size();
        if(i==n-1)
            return 1;
        
        if(dp[i][k]!=-1)
            return dp[i][k];
        
        int x = arr[i]+k-1;
        int y = arr[i]+k+1;
        
        if(k==1)
            x=arr[i]+k;
        
        int a = lower_bound(arr.begin(), arr.end(), x)-arr.begin();
        int b = upper_bound(arr.begin(), arr.end(), y)-arr.begin();
        
        bool ans=0;
        if(a!=n)
        {
            for(int p=a; p<b; p++)
            {
                if(arr[p]-arr[i]==k-1 || arr[p]-arr[i]==k || arr[p]-arr[i]==k+1)
                    ans = ans | solve(p, arr[p]-arr[i], arr);
            }
        }
        return dp[i][k] = ans;
    }
    
    bool canCross(vector<int>& stones) {
        if(stones[1]!=1)
            return 0;
        memset(dp, -1, sizeof(dp));
        return solve(1, 1, stones);
    }
};