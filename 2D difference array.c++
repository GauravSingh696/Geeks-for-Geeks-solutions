class Solution {
  public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat, vector<vector<int>>& opr) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vec(n, vector<int>(m, 0));
        
        for(auto &it : opr) {
            int v = it[0], r1 = it[1], c1 = it[2], r2 = it[3], c2 = it[4];
            vec[r2][c2] += v;
            
            if(r1 > 0 && c1 > 0)
                vec[r1-1][c1-1] += v;
            
            if(r1 > 0)
                vec[r1-1][c2] -= v;
            
            if(c1 > 0)
                vec[r2][c1-1] -= v;
        }
        
        for(int i=0;i<n;i++) {
            for(int j=m-2;j>=0;j--) {
                vec[i][j] += vec[i][j+1];
            }
        }
        
        for(int i=n-2;i>=0;i--) {
            for(int j=0;j<m;j++) {
                vec[i][j] += vec[i+1][j];
            }
        }
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                vec[i][j] += mat[i][j];
            }
        }
        
        return vec;
    }
};
