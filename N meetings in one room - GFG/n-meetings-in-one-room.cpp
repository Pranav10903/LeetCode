// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        pair<int,int>arr[n+1];
        for(int i=0;i<n;i++){
            arr[i].first = end[i];
            arr[i].second = i;
        }
        sort(arr,arr+n);
        int timeLimit = arr[0].first;
        int size = 1;
        for(int i=1;i<n;i++){
            if(start[arr[i].second]>timeLimit){
                timeLimit = arr[i].first;
                size++;
            }
        } return size;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends