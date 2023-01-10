class Solution {
public:
    vector<int> getRow(int numRows) {
        vector<vector<int>>ans;
        for(int i=0;i<=numRows;i++)
        {
            vector<int>partial;
            for(int j=0;j<=i;j++)
            {
                if(j==0||j==i)
                {
                    partial.push_back(1);
                }
                else
                {
                    partial.push_back(ans[i-1][j-1]+ans[i-1][j]);
                }
            } ans.push_back(partial);
        } return ans[numRows];
    }
};