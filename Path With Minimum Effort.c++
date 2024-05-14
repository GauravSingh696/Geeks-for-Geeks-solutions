// 14-05-2024

class Solution {
  public:
    int MinimumEffort(int n, int m, vector<vector<int>> &height) {
        // code here
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        pq.push({0, {0,0}});
        
        while(!pq.empty())
        {
            int step = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            
            pq.pop();
            
            if(row==n-1 && col==m-1)
            {
                return step;
            }
            
            int n_row, n_col;
            
            n_row = row-1;      n_col = col;
            
            if(n_row>=0 && n_col>=0 && n_row<n && n_col<m)
            {
                int value = max(step, abs(height[n_row][n_col] - height[row][col]));
                
                if(value < dist[n_row][n_col])
                {
                    dist[n_row][n_col] = value;
                    pq.push({value, {n_row, n_col}});
                }
            }
            
            
            
            
            n_row = row+1;      n_col = col;
            
            if(n_row>=0 && n_col>=0 && n_row<n && n_col<m)
            {
                int value = max(step, abs(height[n_row][n_col] - height[row][col]));
                
                if(value < dist[n_row][n_col])
                {
                    dist[n_row][n_col] = value;
                    pq.push({value, {n_row, n_col}});
                }
            }
            
            
            
            
            n_row = row;      n_col = col-1;
            
            if(n_row>=0 && n_col>=0 && n_row<n && n_col<m)
            {
                int value = max(step, abs(height[n_row][n_col] - height[row][col]));
                
                if(value < dist[n_row][n_col])
                {
                    dist[n_row][n_col] = value;
                    pq.push({value, {n_row, n_col}});
                }
            }
            
            
            
            n_row = row;      n_col = col+1;
            
            if(n_row>=0 && n_col>=0 && n_row<n && n_col<m)
            {
                int value = max(step, abs(height[n_row][n_col] - height[row][col]));
                
                if(value < dist[n_row][n_col])
                {
                    dist[n_row][n_col] = value;
                    pq.push({value, {n_row, n_col}});
                }
            }
        }
        
        
        return dist[n-1][m-1];
        
    }
};
