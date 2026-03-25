class Solution {
  public:
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
        if(V == 1)
            return {0};
        
        vector<int> result;
        vector<int> indegree(V);
        map<int, vector<int>> adj;
        
        for(vector<int> vec : edges) {
            int u = vec[0];
            int v = vec[1];
            indegree[u]++;
            indegree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        queue<int> que;
        for(int i = 0; i<V; i++) {
            if(indegree[i] == 1)
                que.push(i);
        }
        
        while(V > 2) {
            int size = que.size();
            V -= size;
            
            while(size--) {
                int u = que.front();
                que.pop();
                for(int v:adj[u]) {
                    indegree[v]--;
                    if(indegree[v] == 1)
                        que.push(v);
                }
            }
        }
        
        while(!que.empty()) {
            result.push_back(que.front());
            que.pop();
        }
        return result;
    }
};

