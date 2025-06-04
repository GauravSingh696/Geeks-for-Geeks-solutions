class Solution {
  public:
    int a, b, c;
    vector<vector<vector<int>>> dp;
    
    int solve(int i, int j, int k, string& s1, string& s2, string& s3) {
        if(i>=a || j>=b || k>=c)
            return 0;
            
        if(dp[i][j][k] != -1)
            return dp[i][j][k];
        
        int result = 0;
        
        if(s1[i] == s2[j] && s2[j] == s3[k])
            result = 1 + solve(i+1, j+1, k+1, s1, s2, s3);
        
        else {
            result = max(result , solve(i+1, j, k, s1, s2, s3));
            result = max(result , solve(i, j+1, k, s1, s2, s3));
            result = max(result , solve(i, j, k+1, s1, s2, s3));
            result = max(result , solve(i+1, j+1, k, s1, s2, s3));
            result = max(result , solve(i+1, j, k+1, s1, s2, s3));
            result = max(result , solve(i, j+1, k+1, s1, s2, s3));
            result = max(result , solve(i+1, j+1, k+1, s1, s2, s3));
        }
        
        return dp[i][j][k] = result;
    }
  
    int lcsOf3(string& s1, string& s2, string& s3) {
        a = s1.size() , b = s2.size() , c = s3.size();
        
        dp.assign(a+1, vector<vector<int>>(b+1, vector<int>(c+1, -1)));
        
        return solve(0, 0, 0, s1, s2, s3);
    }
};
