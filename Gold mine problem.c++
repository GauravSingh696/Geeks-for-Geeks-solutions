class Solution {
  public:
    int solve(vector<vector<int>> &mat, int i, int j, vector<vector<int>> &dp) {
        if(i>=row || j>=col || i<0 || j<0)
            return 0;
            
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int up_right   = solve(mat, i-1, j+1, dp);
        int right      = solve(mat, i  , j+1, dp);
        int down_right = solve(mat, i+1, j+1, dp);
        
        return dp[i][j] = mat[i][j] + max({up_right, right, down_right});
    }
  
    int maxGold(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        int result = 0;
        
        vector<vector<int>> dp(row+1, vector<int>(col+1, -1));
        
        for(int i=0;i<row;i++) {
            result = max(result , solve(mat, i, 0, dp));
        }
        
        return result;
    }
};
