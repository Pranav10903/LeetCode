class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
         priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;

        int n=heights.size();
        int m=heights[0].size();

        int delRow[4]={-1,0,1,0};
        int delCol[4]={0,1,0,-1};
        vector<vector<int>> distance(n,vector<int>(m,INT_MAX));
        
        pq.push({0,{0,0}});
        distance[0][0]=0;
        int ans=INT_MAX;
        while(!pq.empty())
        {
            int dist=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();

            if(row==n-1 and col==m-1)
            {
                ans=min(ans,dist);
                continue;
                // return dist;
            }
            for(int i=0;i<4;i++)
            {
                int newRow=row+delRow[i];
                int newCol=col+delCol[i];
                
                if(newRow>=0 and newCol>=0 and newRow<n and newCol<m)
                {
                    int newEffort=max(abs(heights[newRow][newCol]-heights[row][col]),dist);
                    if(newEffort<distance[newRow][newCol])
                    {
                        distance[newRow][newCol]=newEffort;
                        pq.push({newEffort,{newRow,newCol}});
                    }
                }
            }
        }
        return ans==INT_MAX?0:ans;
    }
};