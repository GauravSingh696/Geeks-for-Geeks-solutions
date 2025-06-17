class Solution {
  public:
    int minimumCoins(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        
        int result = INT_MAX;
        int n = arr.size();
        vector<int> pre_sum(n+1, 0);
        
        for(int i=1;i<=n;i++) {
            pre_sum[i] = pre_sum[i-1] + arr[i-1];
        }
        
        for(int i=0;i<n;i++) {
            int high = arr[i] + k;
            int idx = upper_bound(arr.begin(), arr.end(), high) - arr.begin();
            
            int cost = pre_sum[i] + (pre_sum[n] - pre_sum[idx]) - (n-idx) * high;
            
            result = min(result, cost);
        }
        
        return result;
    }
};
