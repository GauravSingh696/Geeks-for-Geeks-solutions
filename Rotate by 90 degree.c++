class Solution {
  public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        vector<vector<int>> res( n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                res[j][i]=mat[i][j];
            }
        }
        reverse(res.begin(),res.end());
        mat=res;
    }
};
