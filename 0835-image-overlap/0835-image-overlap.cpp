class Solution {
public:
    int check(vector<vector<int>>& img1, vector<vector<int>>& img2, int row, int col){
        int n = img1.size();
        int pos = 0;
        for(int i=0; i<n ; i++){
            for(int j=0; j<n; j++){
                if( i+row<n and i+row>=0 and j+col<n and j+col>=0 and img1[i+row][j+col]==1 and img2[i][j]==1){
                    pos++;
                }
            }
        }
        return pos;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size(); 
        int maxi = INT_MIN;
        for(int i=-n;i<n;i++){
            for(int j=-n;j<n;j++){
                maxi = max(maxi,check(img1,img2,i,j));
            }
        }
        return maxi;
    }
};