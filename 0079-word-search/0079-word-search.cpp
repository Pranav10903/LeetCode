class Solution {
 
    private:
    int m,n;
    bool dfsSearch(vector<vector<char>>& board,string word,int ind,int i,int j){
        if(i<0||i>=m||j<0||j>=n||word[ind]!=board[i][j]){
            return false;
        }
        if(ind == word.length()-1) return true;
        char c = board[i][j];
        board[i][j] = '*'; //used
        bool search = dfsSearch(board,word,ind+1,i-1,j)||dfsSearch(board,word,ind+1,i+1,j)||dfsSearch(board,word,ind+1,i,j-1)||dfsSearch(board,word,ind+1,i,j+1);
        board[i][j] = c;
        return search;
    }
    public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.empty()) return true;
        if(board.empty()||board[0].empty()) return false;
        m = board.size();
        n = board[0].size();
        for(int i = 0; i<m ; i++){
            for(int j=0; j<n; j++){
                if(dfsSearch(board,word,0,i,j)) return true;
            }
        }
        return false;
    }  
};