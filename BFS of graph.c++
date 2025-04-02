class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        vector<int> result;
        unordered_map<int, bool> visited;
        queue<int> que;
        
        visited[0] = 1;
        que.push(0);
        
        while(!que.empty()) {
            int val = que.front();
            que.pop();
            
            result.push_back(val);
            
            for(auto it : adj[val]) {
                if(visited[it] == 0) {
                    visited[it] = 1;
                    que.push(it);
                }
            }
        }
        
        return result;
    }
};
