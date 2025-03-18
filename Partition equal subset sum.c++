class Solution {
public:
    vector<vector<int>> dp;
    
    bool solve(vector<int>& arr, int i, int curr, int sum) {
        if (i >= arr.size()) 
            return false;
            
        if (curr == sum) 
            return true;
        
        if (dp[i][curr] != -1) 
            return dp[i][curr];

        bool take = solve(arr, i + 1, curr + arr[i], sum - arr[i]);
        bool not_take = solve(arr, i + 1, curr, sum);

        return dp[i][curr] = take || not_take;
    }
    
    bool equalPartition(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        
        dp.assign(arr.size(), vector<int>(sum + 1, -1));
        
        return solve(arr, 0, 0, sum);
    }
};
