class Solution {
  public:
    int dfs(unordered_map<int, vector<int>> &graph, int src, int &dest, vector<int> &dp) {
        if(src == dest)
            return 1;
        
        if(dp[src] != -1)
            return dp[src];
    
        int count = 0;
        
        for(auto &it : graph[src]) {
            count += dfs(graph, it, dest, dp);
        }
        
        return dp[src] = count;
    }
  
    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        unordered_map<int, vector<int>> graph;
        
        for(auto &it : edges) {
            int u = it[0];
            int v = it[1];
            
            graph[u].push_back(v);
        }
        
        vector<int> dp(V+1, -1);
        
        return dfs(graph, src, dest, dp);
    }
};
