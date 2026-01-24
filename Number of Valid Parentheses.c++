class Solution {
  public:
    void solve(int left, int right, int &result) {
        if(left == 0 && right == 0)
            result++;
        
        if(left > right)    return ;
        
        if(left > 0)
            solve(left-1, right, result);
        
        if(right > 0)
            solve(left, right-1, result);
    }
  
    int findWays(int n) {
        if((n%2) != 0)  return 0;
        
        int result = 0;
        
        solve(n/2, n/2, result);
        
        return result;
    }
};
