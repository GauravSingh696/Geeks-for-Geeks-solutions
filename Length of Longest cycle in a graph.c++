class Solution {
  public:
    void dfs(int i, int t, vector<bool> &vis1, vector<bool> &vis2, vector<int> &timer, vector<vector<int>> &adj, int &temp) {
        vis1[i] = true;
        vis2[i] = true;
        timer[i] = t;
        
        for(int ch : adj[i]) {
            if(!vis1[ch]) {
                dfs(ch, t+1, vis1, vis2, timer, adj, temp);
            } else if(vis2[ch]) {
                temp = max(temp, t+1-timer[ch]);
            }
        }
        
        vis2[i] = false;
        return;
    }
  
    int longestCycle(int v, vector<vector<int>>& edges) {
        vector<vector<int>> adj(v+1);
        vector<bool> vis1(v+1, false);
        vector<bool> vis2(v+1, false);
        vector<int> timer(v+1);
        
        for(auto &it : edges) {
            adj[it[0]].push_back(it[1]);
        }
        
        int result = -1;
        
        for(int i=0;i<=v;i++) {
            if(!vis1[i]) {
                int temp = -1;
                dfs(i, 0, vis1, vis2, timer, adj, temp);
                result = max(result, temp);
            }
        }
        
        return result;
    }
};
