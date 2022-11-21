class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& ent) {
        int n=maze.size(),m=maze[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,0));
        queue<pair<int,int>>q;
        q.push({ent[0],ent[1]});
        visited[ent[0]][ent[1]]=1;
        int step=0;
        int dx[]={1,0,-1,0};
        int dy[]={0,1,0,-1};
        while(!q.empty()){
            int size=q.size();
            step++;
            while(size--){
                pair<int,int>p=q.front();q.pop();
                int row=p.first;
                int col=p.second;
                for(int i=0;i<4;i++){
                    int nrow=row+dx[i];
                    int ncol=col+dy[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                        if(maze[nrow][ncol]!='.')continue;
                        if(visited[nrow][ncol]) continue;
                        if(nrow==0 or nrow==n-1 or ncol==0 or ncol==m-1)return step;
                        visited[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                    
                }
            }
        }
        return -1;
    }
};