class Solution {
  public:
    vector<vector<int>> vec;
  
    int solve(vector<int> &coins, int sum, int i) {
        if(sum==0)  
            return 0;
        
        if(i>=coins.size())
            return INT_MAX;
        
        if(vec[i][sum] != -1)
            return vec[i][sum];
        
        int take=INT_MAX , not_take=INT_MAX;
        
        if(coins[i] <= sum) {
            int temp = solve(coins, sum-coins[i], i);
            
            if(temp != INT_MAX)
                take = 1 + temp;
        }
        
        not_take = solve(coins, sum, i+1);
        
        return vec[i][sum] = min(take, not_take);
    }
  
    int minCoins(vector<int> &coins, int sum) {
        int n = coins.size();
        vec.assign(n, vector<int>(sum+1, -1));
        
        int result = solve(coins, sum, 0);
        
        return result==INT_MAX ? -1 : result ;
    }
};
