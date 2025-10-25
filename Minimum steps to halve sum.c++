class Solution {
  public:
    int minOperations(vector<int>& arr) {
        double sum = accumulate(arr.begin(), arr.end(), 0);
        double half = sum / 2.0;
        
        priority_queue<double> pq(arr.begin(), arr.end());
        
        int result = 0;
        
        while(true) {
            double val = pq.top();
            double new_sum = sum - val/2.0;
            pq.pop();
            result++;
            
            if(new_sum <= half) {
                break;
            }
            
            pq.push(val/2.0);
            sum -= val/2.0;
        }
        
        return result;
    }
};
