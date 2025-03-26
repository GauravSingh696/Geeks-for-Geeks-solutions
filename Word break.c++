class Solution {
  public:
    bool wordBreak(string &s, vector<string> &dict) {
        int n = s.size() , m = dict.size();
        vector<int> dp(n+1, 0);
        dp[n] = 1;
        
        for(int i=n-1;i>=0;i--) {
            for(int j=m-1;j>=0;j--) {
                int k=0;
                
                for(int l=i;l<n && k<dict[j].size();l++) {
                    if(s[l] == dict[j][k])
                        k++;
                    
                    else
                        break;
                }
                
                if(k == dict[j].size())
                    dp[i] |= dp[i+k];
            }
        }
        
        return dp[0];
    }
};
