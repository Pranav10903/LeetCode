//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    
    public:
    void dfs(vector<vector<int>>& matrix,int i,int j,int N,int M,int dX[],int dY[]){
       matrix[i][j]=0;
       for(int k=0;k<4;k++){
           int nr=i+dX[k];
           int nc=j+dY[k];
           if(nr>=0 and nr<N and nc>=0 and nc<M and matrix[nr][nc]==1){
               dfs(matrix,nr,nc,N,M,dX,dY);
           }
       }
   }
   void dfs1(vector<vector<int>>& matrix,vector<vector<bool>>&vis,int i,int j,int N,int M,int dX[],int dY[]){
       vis[i][j]=true;
       for(int k=0;k<4;k++){
           int nr=i+dX[k];
           int nc=j+dY[k];
           if(nr>=0 and nr<N and nc>=0 and nc<M and matrix[nr][nc]==1 and vis[nr][nc]==false){
               dfs1(matrix,vis,nr,nc,N,M,dX,dY);
           }
       }
   }
   int closedIslands(vector<vector<int>>& matrix, int N, int M) {
       // Code here
       int dX[]={-1,0,1,0};
       int dY[]={0,1,0,-1};
       for(int i=0;i<N;i++){
           int j=0;
           if(matrix[i][j]==1){
               dfs(matrix,i,j,N,M,dX,dY);
           }
           j=M-1;
           if(matrix[i][j]==1){
               dfs(matrix,i,j,N,M,dX,dY);
           }
       }
       for(int j=0;j<M;j++){
           int i=0;
           if(matrix[i][j]==1){
               dfs(matrix,i,j,N,M,dX,dY);
           }
           i=N-1;
           if(matrix[i][j]==1){
               dfs(matrix,i,j,N,M,dX,dY);
           }
       }
       int count=0;
       vector<vector<bool>>vis(N,vector<bool>(M,false));
       for(int i=0;i<N;i++){
           for(int j=0;j<M;j++){
               if(vis[i][j]==false and matrix[i][j]==1){
                   dfs1(matrix,vis,i,j,N,M,dX,dY);
                   count++;
               }
           }
       }
       return count;
   }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends