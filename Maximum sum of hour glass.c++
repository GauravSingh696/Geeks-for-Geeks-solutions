// 25-04-2024

class Solution {
  public:
    int findMaxSum(int n, int m, vector<vector<int>> mat) {
        // code here
        
        int temp = 0;
        if(n<3 || m<3)
            return -1;
        
        for(int i=1;i+1<n;i++)
        {
            for(int j=1;j+1<m;j++)
            {
                int sum = mat[i][j] + mat[i-1][j] + mat[i+1][j] + mat[i-1][j-1] + mat[i-1][j+1] + mat[i+1][j-1] + mat[i+1][j+1];
                temp = max(temp, sum);
            }
        }
        
        return temp;
    }
};
