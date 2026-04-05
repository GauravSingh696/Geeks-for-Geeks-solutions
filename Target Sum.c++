class Solution {
  public:
    vector<vector<int>> dp;
    
    int solve(int i, vector<int>& arr, int &tar, int curr_sum) {
        if(i == arr.size()) {
            if(curr_sum == tar) return 1;
            return 0;
        }
        
        if(dp[i][curr_sum+1000] != -1) return dp[i][curr_sum+1000];
        
        int take     = solve(i+1, arr, tar, curr_sum+arr[i]);
        int not_take = solve(i+1, arr, tar, curr_sum-arr[i]);
        
        return dp[i][curr_sum+1000] = take + not_take;
    }
    
    int totalWays(vector<int>& arr, int target) {
        dp.resize(51, vector<int>(3000, -1));
        
        return solve(0, arr, target, 0);
    }
};
