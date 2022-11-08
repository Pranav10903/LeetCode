//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n];
        for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int , int>>> q;
        vector<int> dist(n, 1e9);
        vector<int> paths(n , 0);
        q.push({0, 0});
        int mod = (int)(1e9 + 7);
        dist[0] = 0;
        paths[0] = 1;
        while(!q.empty()){
            int node = q.top().second;
            int dis = q.top().first;
            q.pop();
            for(auto it: adj[node]){
                int adjNode = it.first;
                int eW = it.second;
                if(dis+eW < dist[adjNode]){
                    dist[adjNode] = dis + eW;
                    q.push({ dist[adjNode],adjNode});
                    paths[adjNode] = paths[node];
                }
                else if(dist[adjNode]==dis+eW){
                    paths[adjNode] = (paths[adjNode] +paths[node])% mod;
                }
            }
        }
        return paths[n-1] % mod;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends