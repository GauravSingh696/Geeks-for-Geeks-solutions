class Solution {
  public:
    vector<vector<vector<int>>> dp;
  
    int solve(vector<int>& prices, int k, int i, bool canbuy) {
        if(k==0 || i>=prices.size())
            return 0;
        
        if(dp[i][k][canbuy] != -1)
            return dp[i][k][canbuy];
        
        int take = 0 , not_take = 0;
        
        if(canbuy) {
            take     = -prices[i] + solve(prices, k, i+1, false);
            not_take = solve(prices, k, i+1, true);
        }
        
        else {
            take     = prices[i] + solve(prices, k-1, i+1, true);
            not_take = solve(prices, k, i+1, false);
        }
        
        return dp[i][k][canbuy] = max(take , not_take);
    }
  
    int maxProfit(vector<int> &prices) {
        bool canbuy = true;
        int n = prices.size();
        dp.assign(n+1, vector<vector<int>>(3, vector<int>(2+1 , -1)));
        
        return solve(prices, 2, 0, canbuy);
    }
};
