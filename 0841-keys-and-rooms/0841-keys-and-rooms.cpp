class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n);
        vis[0] = 1;
        stack<int> st;
        st.push(0);
        while(!st.empty()){
            int node = st.top();
            st.pop();
            for(auto it : rooms[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    st.push(it);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0) return false;
        }
        return true;
    }
};