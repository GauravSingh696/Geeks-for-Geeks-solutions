class Solution {
  public:
    int maxSum(vector<int> &a) {
        int sum = 0, n = a.size();
        int prev = 0;
        for(int i=0; i<n; i++) {
            prev += i * a[i];
            sum += a[i];
        }
        
        int ans = prev;
        
        for(int i=1;i<n;i++) {
            int curr = prev - (sum - a[i-1]) + a[i-1]*(n-1);
            prev = curr;
            
            ans = max(ans, curr);
        }
        
        return ans;
    }
};
