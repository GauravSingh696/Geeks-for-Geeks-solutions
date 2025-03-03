class Solution {
  public:
    int solve(int idx, int prev, vector<int> &arr, vector<vector<int>> &dp) {
        if(idx < 0)
            return 0;
        
        int take = INT_MIN;
        int not_take = solve(idx-1 , prev , arr , dp);
        
        if(dp[idx][prev] != -1)
            return dp[idx][prev];
        
        if(prev == arr.size()) {
            take = 1 + solve(idx-1 , idx, arr, dp);
        }
        
        else if(arr[idx] < arr[prev]) {
            take = 1 + solve(idx-1 , idx , arr, dp);
        }
        
        return dp[idx][prev] = max(take , not_take);
    }
  
    int lis(vector<int>& arr) {
        int n = arr.size();
        int prev = n;
        
        vector<vector<int>> dp(n, vector<int>(n+1 , -1));
        
        return solve(n-1, prev, arr, dp);
    }
};
