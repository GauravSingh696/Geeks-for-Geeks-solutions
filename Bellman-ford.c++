class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dict(V, 1e8);
        dict[src] = 0;
        
        for(int i=0;i<=V;i++) {
            for(auto &it : edges) {
                int u = it[0];
                int v = it[1];
                int w = it[2];
                
                if(dict[u] != 1e8 && dict[u]+w < dict[v]) {
                    dict[v] = dict[u] + w;
                }
            }
        }
        
        for(auto &it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            
            if(dict[u] != 1e8 && dict[u]+w < dict[v]) {
                return {-1};
            }
        }
        
        return dict;
    }
};
