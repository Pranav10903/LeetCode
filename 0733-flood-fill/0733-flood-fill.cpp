class Solution {
public:
    void dfs(vector<vector<int>> &image, int r, int c, int val, int newC){
        if(r<0 || r>=image.size() || c<0 ||c>=image[0].size() || image[r][c]== newC || image[r][c]!=val ){
            return;
        }
        image[r][c] = newC;
        dfs(image,r+1,c,val,newC);
        dfs(image,r-1,c,val,newC);
        dfs(image,r,c+1,val,newC);
        dfs(image,r,c-1,val,newC);         
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)     {
        int val = image[sr][sc];
        dfs(image,sr,sc,val,newColor);
        return image;
    }
};