class Solution {
public:
    void dfs(vector<vector<int>>& h,vector<vector<bool>> &vis,int i,int j)
	{
		int m=h.size();
		int n=h[0].size();

		vis[i][j]=true; //marking that particular element as true so it will help in future

		//up
		if(i-1>=0 && vis[i-1][j]!=true && h[i-1][j]>=h[i][j])
			dfs(h,vis,i-1,j);

		//left
		if(j-1>=0 && vis[i][j-1]!=true && h[i][j-1]>=h[i][j])
			dfs(h,vis,i,j-1);

		//down
		if(i+1<m && vis[i+1][j]!=true && h[i+1][j]>=h[i][j])
			dfs(h,vis,i+1,j);

		//right
		if(j+1<n && vis[i][j+1]!=true && h[i][j+1]>=h[i][j])
			dfs(h,vis,i,j+1);
	}


	vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights){

		vector<vector<int>>res;

		int m=heights.size();
		int n=heights[0].size();

		vector<vector<bool>>pacific(m,vector<bool>(n)); /*making seperate matix for pacif and atlanti and will be storing bool values if possible or not*/
		vector<vector<bool>>atlantic(m,vector<bool>(n));

		for(int i=0;i<m;i++)     //In this storing left values for pacific and right values for atlantic
		{
			dfs(heights,pacific,i,0);
			dfs(heights,atlantic,i,n-1);
		}
		for(int j=0;j<n;j++)    //In this storing top values for pacific and bottom values for atlantic
		{
			dfs(heights,pacific,0,j);
			dfs(heights,atlantic,m-1,j);
		}

		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(pacific[i][j] && atlantic[i][j])
				{
					res.push_back({i,j});
				}
			}
		}
		return res;
	}

};