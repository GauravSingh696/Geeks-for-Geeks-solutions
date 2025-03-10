class Solution {
  public:
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        int m = s1.size();
        int n = s2.size();
        
        vector<vector<int>> vec(m+1, vector<int>(n+1));
        
        for(int i=0;i<=m;i++) {
            for(int j=0;j<=n;j++) {
                if(i==0)
                    vec[i][j] = j;
                
                else if(j==0)
                    vec[i][j] = i;
                
                else if(s1[i-1] == s2[j-1])
                    vec[i][j] = vec[i-1][j-1];
                
                else
                    vec[i][j] = 1 + min({vec[i-1][j] , vec[i][j-1] , vec[i-1][j-1]});
            }
        }
        
        return vec[m][n];
    }
};
