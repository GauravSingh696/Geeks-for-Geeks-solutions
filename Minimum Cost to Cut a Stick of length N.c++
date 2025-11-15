class Solution {
  public:
    int dp[103][103];
    
    int solve(int l, int r, vector<int> &cuts) {
        if(r-l == 1)    return 0;
        if(dp[l][r] != -1)  return dp[l][r];
        
        int result = INT_MAX;
        
        for(int idx=l+1;idx<r;idx++) {
            int cost = (cuts[r] - cuts[l]) + solve(l, idx, cuts) + solve(idx, r, cuts);
            
            result = min(result, cost);
        }
        
        return dp[l][r] = result;
    }
  
    int minCutCost(int n, vector<int>& cuts) {
        memset(dp, -1, sizeof(dp));
        cuts.push_back(0);
        cuts.push_back(n);
        
        sort(cuts.begin(), cuts.end());
        
        return solve(0, cuts.size()-1, cuts);
    }
};
