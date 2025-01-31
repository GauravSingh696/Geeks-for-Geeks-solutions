class Solution {
  public:
    bool checker(int t, int r, int c, vector<vector<int>> &mat, int n) {
        for(int j=0 ; j<n ; j++) {
            if(mat[r][j] == t)
                return false;
        }
        
        for(int i=0 ; i<n ; i++) {
            if(mat[i][c] == t) 
                return false;
        }
        
        int temp1 = r-(r%3);
        int temp2 = c-(c%3);
        
        for(int i=temp1 ; i<temp1+3 ; i++) {
            for(int j=temp2 ; j<temp2+3 ; j++) {
                if(mat[i][j] == t)
                    return false;
            }
        }
        
        return true;
    }
  
    bool helper(int row, int col, vector<vector<int>> &mat, int n) {
        if(row==n)  return true;
        
        if(col==n)
            return helper(row+1 , 0 , mat, n);
            
        if(mat[row][col] != 0)
            return helper(row, col+1, mat, n);
        
        for(int k=1 ; k<=9 ; k++) {
            if(checker(k, row, col, mat, n)) {
                mat[row][col] = k;
                
                if(helper(row, col+1, mat, n))
                    return true;
                
                mat[row][col] = 0;
            }
        }
        
        return false;
    }
  
    void solveSudoku(vector<vector<int>> &mat) {
        helper(0, 0, mat, mat.size());
    }
};
