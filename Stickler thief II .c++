class Solution {
  public:
    int solve(vector<int> &arr, int i, int end, vector<int> &dp) {
        if(i > end)
            return 0;
        
        if(dp[i] != -1) 
            return dp[i];

        int take = arr[i] + solve(arr, i+2, end, dp);
            
        int not_take = solve(arr, i+1, end, dp);
        
        return dp[i] = max(take , not_take);
    }
  
    int maxValue(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> dp1(n+1, -1);
        vector<int> dp2(n+2, -1);
        
        return max(solve(arr, 0, n-2, dp1) , solve(arr, 1, n-1, dp2));
    }
};
