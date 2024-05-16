// 16-05-2024

class Solution {
public:
    int result = 0;
    
    int dfs(vector<int> adj[], vector<int> &vis, int start)
    {
        vis[start] = 1;
        int count = 0;
        
        for(auto it : adj[start])
        {
            if(!vis[it])
            {
                int res = dfs(adj, vis, it);
                
                if(res % 2 == 0)
                    result++;
                
                else
                    count += res;
            }
        }
        
        return count+1;
    }
    
	int minimumEdgeRemove(int n, vector<vector<int>>edges){
	    // Code here
	    
	    vector<int> adj[n];
	    
	    for(int i=0;i<edges.size();i++)
	    {
	        adj[edges[i][0] - 1].push_back(edges[i][1] - 1);
	        adj[edges[i][1] - 1].push_back(edges[i][0] - 1);
	    }
	    
	    vector<int> vis(n, 0);
	    
	    dfs(adj, vis, 0);
	    
	    return result;
	    
	}
};
