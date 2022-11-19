class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        if(grid[0][0] ==1 || grid[n-1][n-1] == 1) return -1;
        if(n==1 && m== 1) return 1;  // if source and destination is same cell 
        
        vector<vector<int>> dist(n, vector<int>(m,1e9));
        //{dist,{row,col}}
        queue<pair<int,pair<int, int>>> q;
        q.push({1,{0,0}});
        dist[0][0] = 0;
        
        vector<int> drow =  {-1,-1,-1,0,0,1,1,1};
        vector<int> dcol =  {-1,0,1,-1,1,-1,0,1};
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;
            for(int i = 0; i<8; i++)
            {
                int nrow = row+drow[i];
                int ncol = col+dcol[i];
                if(nrow>=0 && nrow< n && ncol >=0 && ncol <m && grid[nrow][ncol] == 0 &&                        1+dis< dist[nrow][ncol])
                {
                    dist[nrow][ncol] = 1+dis;
                    if(nrow == n-1 && ncol == m-1) return 1+dis;
                    q.push({1+dis,{nrow,ncol}});       
                }
            }
        }
        return -1;
    }
};