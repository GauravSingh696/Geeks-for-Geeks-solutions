class Solution {
  public:
    int solve(vector<int> &arr, int n, int i, int prev_idx, vector<vector<int>> &dp) {
        if(i == n) {
            return 0;
        }
        
        if(dp[i][prev_idx+1] != -1) {
            return dp[i][prev_idx+1];
        }
        
        int incl = 0, excl = 0;
        
        if(prev_idx == -1 || arr[i] > arr[prev_idx]) {
            incl = arr[i] + solve(arr, n, i+1, i, dp);
        }
        
        excl = 0 + solve(arr, n, i+1, prev_idx, dp);
        
        return dp[i][prev_idx+1] = max(incl, excl);
    }
  
    int maxSumIS(vector<int>& arr) {
        int n = arr.size();
        int prev_idx = -1;
        int sum = 0;
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        
        return solve(arr, n, 0, prev_idx, dp);
    }
};
