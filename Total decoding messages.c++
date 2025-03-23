class Solution {
  public:
    vector<int> dp;
  
    int solve(string str, int i) {
        if(i >= str.size())
            return 1;
        
        if(dp[i] != -1)
            return dp[i];
        
        int choice1 = 0 , choice2 = 0;
        
        if(str[i] >= '1' && str[i] <= '9')
            choice1 = solve(str, i+1);
        
        string part = str.substr(i, 2);
        
        if(i<str.size()-1 && part>="10" && part<="26") 
            choice2 = solve(str, i+2);
        
        return dp[i] = (choice1 + choice2);
    }
  
    int countWays(string &digits) {
        dp.assign(digits.size()+1, -1);
        
        return solve(digits, 0);
    }
};
