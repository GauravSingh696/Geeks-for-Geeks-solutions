class Solution {
  public:
    vector<vector<int>> dp;
    
    int solve(string &s1, int i, string &s2, int j) {
        if(i>=s1.size() || j>=s2.size())
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
            
        if(s1[i] == s2[j])
            return 1 + solve(s1, i+1, s2, j+1);
        
        int take_s1 = solve(s1, i, s2, j+1);
        int take_s2 = solve(s1, i+1, s2, j);
        
        return dp[i][j] = max(take_s1 , take_s2);
    }
  
    int lcs(string &s1, string &s2) {
        int i=0 , j=0;
        int n1 = s1.size() , n2 = s2.size();
        
        dp.assign(n1+1 , vector<int>(n2+1 , -1));
        
        return solve(s1, i, s2, j);
    }
};
