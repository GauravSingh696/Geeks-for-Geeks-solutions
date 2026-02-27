class Solution {
  public:
    int countSquare(vector<vector<int>>& mat, int x) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> prefix_sum(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                prefix_sum[i][j] = mat[i][j];
                
                //add top
                if(i>0) prefix_sum[i][j] += prefix_sum[i-1][j];
                if(j>0) prefix_sum[i][j] += prefix_sum[i][j-1];
                if(i>0 && j>0) prefix_sum[i][j] -= prefix_sum[i-1][j-1];
            }
        }
        
        int count = 0;
        
        for(int r=0;r<n;r++) {
            for(int c=0;c<m;c++) {
                // maximum possible size form this position
                for(int size=1;(r+size-1)<n && (c+size-1)<m;size++) {
                    int br = r+size-1;
                    int bc = c+size-1;
                    int sum = prefix_sum[br][bc];
                    
                    if(r>0) sum -= prefix_sum[r-1][bc];
                    if(c>0) sum -= prefix_sum[br][c-1];
                    if(r>0 && c>0) sum += prefix_sum[r-1][c-1];
                    if(sum == x) count++;
                }
            }
        }
        
        return count;
    }
};
