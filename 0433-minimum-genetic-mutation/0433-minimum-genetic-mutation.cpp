class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int size = bank.size(); 
        unordered_set<string> dictionary; 
        for(int i = 0; i < size; i++) {
            dictionary.insert(bank[i]);
        }
        if(dictionary.find(end) == dictionary.end())
        {
            return -1;
        }
        vector<char> available = {'A', 'C', 'G', 'T'};
        unordered_set<string> vis;
        int ans = 0; // declare ans variable 
        queue<string> q; // define queue to start bfs
        q.push(start); // push starting word into the queue
        vis.insert(start); // insert into vis
        // starting bfs
        while(!q.empty())
        {
            int n = q.size(); // extract size of queue
            while(n--)
            {
                string curr = q.front(); // curr word 
                q.pop(); // pop from queue
                if(curr == end) // if curr word equals to end, return ans from here
                {
                    return ans;
                }
                // now for every index of curr word
                for(int i = 0; i < 8; i++)
                {
                    char orig = curr[i];        
                    // we will try to replace every available choice
                    for(int j = 0; j < 4; j++) 
                    {   
                        curr[i] = available[j]; // replace character                   
                        // if it is present into the dictionary
                        if(dictionary.find(curr) != dictionary.end())
                        {
                            // also we haven't seen it previously
                            if(vis.find(curr) == vis.end())
                            {
                                q.push(curr); // then push into queue
                                vis.insert(curr); // and also put into vis
                            }
                        }
                    }
                    // now replace with again original character,
                    // for further check
                    curr[i] = orig;
                }
            }
            ans++; // increment answer
        }
        return -1; // still we 
    }
};