class Solution {
public:
    int ans = 0;
    int minReorder(int n, vector<vector<int>>& arr) {
        vector<int>neighbour[n],adj[n];
        for(auto it:arr){
            neighbour[it[0]].push_back(it[1]);
            neighbour[it[1]].push_back(it[0]); // creating a neighbour list containing all neighbours
            adj[it[0]].push_back(it[1]); // creating an adj list based on connections array to check reachability
        }
        queue<int>q;
        vector<int>visited(n,0);
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            visited[node] = 1;          //BFS
            q.pop();
            for(auto Neighbour:neighbour[node]){
                if(!visited[Neighbour]){
                    bool canReach = false;   //Checking if neighbours of current node are visited
                    for(auto AdjacenttoNeighbour:adj[Neighbour]){ // if not visited check if the (prev node) i.e node itself is reachable from the neighbour through adj[] list.
                        if(AdjacenttoNeighbour == node){  
                            canReach = true;  // if reachable dont increment ans
                            q.push(Neighbour);
                            break;
                        }
                    }
                    if(!canReach) {
                        ans++;  // if not reachable increment ans and push neighbour into the queue
                        q.push(Neighbour);
                    }
                }
            }
        }
        return ans;
    }
};