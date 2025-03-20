class Solution {
  public:
    vector<int> dp;
    
    int solve(vector<int>& arr, int i) {
        if(i>=arr.size())
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        int take     = arr[i] + solve(arr, i+2);
        int not_take = solve(arr, i+1);
        
        return dp[i] = max(take , not_take);
    }
  
    int findMaxSum(vector<int>& arr) {
        dp.assign(arr.size()+1 , -1);
        
        return solve(arr, 0);
    }
};
