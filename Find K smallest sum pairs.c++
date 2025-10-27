class Solution {
  public:
    typedef pair<long long, pair<int, int>> pr;
    
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
        int n1 = arr1.size(), n2 = arr2.size();
        vector<vector<int>> result;
        priority_queue<pr, vector<pr>, greater<>> pq;
        
        for(int i=0;i<k && i<n1;i++) {
            for(int j=0;j<k && j<n2;j++) {
                long long sum = arr1[i] + arr2[j];
                
                pq.push({sum , {arr1[i], arr2[j]}});
            }
        }
        
        while(k && !pq.empty()) {
            int a = pq.top().second.first;
            int b = pq.top().second.second;
            pq.pop();
            
            result.push_back({a, b});
            k--;
        }
        
        return result;
    }
};
