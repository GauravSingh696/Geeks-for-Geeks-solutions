class Solution {
  public:
    int solve(int i, int sum1, int sum2, int &n, vector<int> &arr, int &diff, vector<vector<vector<int>>> &dp) {
        if(i == n) {
            if(sum1-sum2 == diff) return 1;
            else return 0;
        }
        
        if(dp[i][sum1][sum2] != -1) return dp[i][sum1][sum2];
        
        int op1 = solve(i+1, sum1+arr[i], sum2, n, arr, diff, dp);
        int op2 = solve(i+1, sum1, sum2+arr[i], n, arr, diff, dp);
        
        return dp[i][sum1][sum2] = op1 + op2;
    }
  
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (sum+1, vector<int> (sum+1, -1)));
        
        return solve(0, 0, 0, n, arr, diff, dp);
    }
};
