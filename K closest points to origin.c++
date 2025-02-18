class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> pq;
        
        for(auto it : points) {
            int x = it[0] , y = it[1];
            
            int val = x*x + y*y;
            
            val = sqrt(val);
            
            pq.push({val, {x,y}});
        }
        
        vector<vector<int>> result;
        
        while(!pq.empty()) {
            if(k==0)
                break;
            
            result.push_back({pq.top().second.first , pq.top().second.second});
            pq.pop();
            k--;
        }
        
        return result;
    }
};
