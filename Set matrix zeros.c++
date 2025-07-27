class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        unordered_set<int> st_row, st_col;
        int row = mat.size();
        int col = mat[0].size();
        
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(mat[i][j] == 0) {
                    st_row.insert(i);
                    st_col.insert(j);
                }
            }
        }
        
        for(int i : st_row) {
            for(int j=0;j<col;j++) {
                mat[i][j] = 0;
            }
        }
        
        for(int j : st_col) {
            for(int i=0;i<row;i++) {
                mat[i][j] = 0;
            }
        }
    }
};
