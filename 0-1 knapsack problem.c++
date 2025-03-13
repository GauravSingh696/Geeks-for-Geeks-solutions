class Solution {
  public:
    vector<vector<int>> vec;
  
    int solve(int w, vector<int> &val, vector<int> &wt, int i) {
        if(i>=val.size() || w==0)
            return 0;
            
        if(vec[i][w] != -1)
            return vec[i][w];
        
        int pick = 0;
        
        if(w>=wt[i])
            pick = val[i] + solve(w-wt[i] , val, wt, i+1);
            
        int not_pick = solve(w, val, wt, i+1);
        
        return vec[i][w] = max(pick , not_pick);
    }
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        vec.assign(val.size()+1, vector<int> (W+1, -1));
        
        return solve(W, val, wt, 0);
    }
};
