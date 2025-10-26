class Solution {
  public:
    int minCost(vector<int>& arr) {
        priority_queue<int, vector<int>, greater<>> pq(arr.begin(), arr.end());
        
        int result = 0;
        
        while(pq.size() > 1) {
            int r1 = pq.top();  pq.pop();
            int r2 = pq.top();  pq.pop();
            
            result += r1 + r2;
            
            pq.push(r1 + r2);
        }
        
        return result;
    }
};
