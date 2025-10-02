class Solution {
  public:
    void solve(int i, int n, int k, vector<int> vec, vector<vector<int>> &result) {
        if(n == 0 && k == 0) {
            result.push_back(vec);
        }
        
        if(n <= 0 || k <= 0)
            return ;
        
        for(int j=i;j<=9;j++) {
            vec.push_back(j);
            solve(j+1, n-j, k-1, vec, result);
            vec.pop_back();
        }
    }
  
    vector<vector<int>> combinationSum(int n, int k) {
        vector<vector<int>> result;
        vector<int> vec;
        
        solve(1, n, k, vec, result);
        
        return result;
    }
};
