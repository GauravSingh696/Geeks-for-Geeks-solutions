class Solution {
  public:
    int solve(string &s, int i, int j, vector<vector<int>> &vec) {
        if(i>j)     
            return 0;
        
        if(i==j)
            return 1;
        
        if(vec[i][j] != -1)
            return vec[i][j];
            
        if(s[i] == s[j]) {
            return 2 + solve(s, i+1, j-1, vec);
        }
        
        return vec[i][j] = max(solve(s, i+1, j, vec) , solve(s, i, j-1, vec));
    }
  
    int longestPalinSubseq(string &s) {
        int n = s.size();
        vector<vector<int>> vec(n+1, vector<int> (n+1, -1));
        
        return solve(s, 0, n-1, vec);
    }
};
