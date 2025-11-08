class Solution {
  public:
    int solve(int row, int col, vector<vector<int>> &mat, int &k, int coins, vector<vector<vector<int>>> &dp) {
        if(row >= mat.size() || col >= mat[0].size()) {
            return 0;
        }
        
        coins += mat[row][col];
        
        if(coins > k)   return 0;
        
        if(row == mat.size()-1 && col == mat[0].size()-1 && coins == k) {
            return 1;
        }
        
        if(dp[row][col][coins] != -1)
            return dp[row][col][coins];
        
        int right = solve(row, col+1, mat, k, coins, dp);
        int down  = solve(row+1, col, mat, k, coins, dp);
        
        return dp[row][col][coins] = right + down;
    }
  
    int numberOfPath(vector<vector<int>>& mat, int k) {
        int coins = 0;
        int row = mat.size(), col = mat[0].size();
        vector<vector<vector<int>>> dp(row+1, vector<vector<int>>(col+1, vector<int>(k+1, -1)));
        
        return solve(0, 0, mat, k, coins, dp);
    }
};
