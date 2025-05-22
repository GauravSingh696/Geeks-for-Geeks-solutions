class Solution {
  public:
    vector<vector<int>> dp;
    
    int solve(string s, int i, int j) {
        if(i>=j)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        else if (s[i] == s[j]) {
            return dp[i][j] = solve(s, i+1, j-1);
        }
        
        else {
            int first  = 1 + solve(s, i+1, j);
            int second = 1 + solve(s, i, j-1);
            
            return dp[i][j] = min(first, second);
        }
    }
  
    int minDeletions(string s) {
        dp.assign(s.size()+1, vector<int> (s.size()+1, -1));
        
        return solve(s, 0, s.size()-1);
    }
};
