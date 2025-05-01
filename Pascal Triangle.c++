class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        // code here
        vector<vector<int>> res;
        for(int i = 0; i<n;i++){
            vector<int> temp(i+1,1);
            res.push_back(temp);
        }
        for(int i = 2; i< n;i++){
            for(int j = 1; j < i;j++)
                res[i][j] = res[i-1][j-1]+res[i-1][j];
        }
        return res[n-1];
    }
};
