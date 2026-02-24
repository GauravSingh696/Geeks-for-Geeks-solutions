class Solution {
  public:
    void dfs(unordered_map<int, vector<int>> &graph, vector<int> &result, vector<bool> &visited, int child) {
        visited[child] = true;        
        result.push_back(child);
        
        for(auto node : graph[child]) {
            if(!visited[node]) {
                dfs(graph, result, visited, node);
            }
        }
    }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        unordered_map<int, vector<int>> graph;
        
        for(int i=0;i<adj.size();i++) {
            for(int j=0;j<adj[i].size();j++) {
                graph[i].push_back(adj[i][j]);
            }
        }
        
        vector<int> result;
        vector<bool> visited(10001, false);
        
        dfs(graph, result, visited, 0);
        
        return result;
    }
};
