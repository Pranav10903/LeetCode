//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //code here.
            int mod = 1e9 + 7;
            int m = pat.size();
            long long sum = 0;
            long long desiredSum = 0;
            for(auto &e : pat){
                desiredSum += (int)e;
                desiredSum %= mod;
            }
            
            for(int i = 0; i < m; i++){
                sum += (int)txt[i];
                sum %= mod;
            }
            vector<int> ans;
            for(int i = m; i <= txt.length(); i++){
                if(sum == desiredSum){
                    int j = i - m;
                    bool isMatching = true;
                    int k = 0;
                    for(; k < m; j++, k++){
                        if(txt[j] != pat[k]){
                            isMatching = false;
                            break;
                        }
                    }
                    if(isMatching){
                        ans.push_back(i - m + 1);
                    }
                }
                sum -= (int)txt[i - m];
                if(i < txt.length()){
                    sum += (int)txt[i];
                    sum %= mod;
                }
            }
            if(ans.empty()){
                ans.push_back(-1);
            }
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends