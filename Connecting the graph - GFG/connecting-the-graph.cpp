//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    int findPar(int node,vector<int> &parent)
    {
        if(node==parent[node]) return node;
        return parent[node]=findPar(parent[node],parent);
    }
public:
    int Solve(int n, vector<vector<int>>& connections) {
        int totalEdge=connections.size();
        if(totalEdge<n-1) return -1; // (n-1) is minimum edge required to connect all n nodes
        
        vector<int> parent(n),rank(n,0);
        
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        int edgeFormed=0;
        for(auto it:connections)
        {  //simple union
            int u=findPar(it[0],parent);
            int v=findPar(it[1],parent);
            if(u!=v)
            {
                if(rank[u]<rank[v])
                {
                    parent[u]=v;
                }
                else if(rank[v]<rank[u])
                {
                    parent[v]=u;
                }
                else
                {
                    parent[u]=v;
                    rank[v]++;
                }
                edgeFormed++;
            }  
        }
        return (n-1)-edgeFormed; // extra edges
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends