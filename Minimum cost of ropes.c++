// 11-09-2024

class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        // Your code here
        // vector<long long> result;
        long long sum = 0;
        
        priority_queue<long long , vector<long long> , greater<long long>> pq;
        
        for(auto &it : arr)
            pq.push(it);
        
        while(pq.size() > 1)
        {
            int a = pq.top();       pq.pop();
            int b = pq.top();       pq.pop();
            
            sum += a+b;
            
            pq.push(a+b);
        }
        
        return sum;
        
    }
};
