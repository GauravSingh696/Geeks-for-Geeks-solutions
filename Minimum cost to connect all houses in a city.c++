class Solution {
  public:
    int minCost(vector<vector<int>>& houses) {
        int n = houses.size();
        
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        
        vector<bool> visited(n, false);
        pq.push({0,0});
        
        int sum = 0;
        
        while(!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            
            int wt = node.first;
            int idx = node.second;
            
            if(visited[idx])
                continue;
            
            visited[idx] = true;
            sum += wt;
            
            for(int i=0;i<n;i++) {
                if(!visited[i]) {
                    int new_wt = abs(houses[idx][0] - houses[i][0]) + abs(houses[idx][1] - houses[i][1]);
                    pq.push({new_wt, i});
                }
            }
        }
        
        return sum;
    }
};
