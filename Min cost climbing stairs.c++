class Solution {
  public:
    int solve(int i, int n, vector<int> &cost, vector<int> &vec) {
        if(i>=n)
            return 0;
        
        if(vec[i] != -1)
            return vec[i];
        
        return vec[i] = cost[i] + min(solve(i+1, n, cost, vec), solve(i+2, n, cost, vec));
    }
  
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> vec(n, -1);
        
        return min(solve(0, n, cost, vec), solve(1, n, cost, vec));
    }
};
