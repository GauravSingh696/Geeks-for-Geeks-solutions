class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        int rows = mat.size(), maxi = 0;
        
        for(int i=0;i<rows;i++){
            int rowsum = 0, colsum = 0;
            
            for(int j=0;j<rows;j++){
                rowsum  += mat[i][j];
                colsum  += mat[j][i];
            }
            
            maxi = max({colsum, maxi, rowsum});
        }
        
        int operations = 0;
        
        for(auto it : mat) {
            int row_sum = accumulate(it.begin(), it.end(), 0);
            
            operations += maxi - row_sum;
        }
        
        return operations;
    }
};
