// 25-06-2026

class Solution {
  public:
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        // code here
        int m=mat.size();
        int n=mat[0].size();
        
        for(int i=0 ; i< m ; i++)
        {
            queue<int> que;
            
            for(int j=0;j<n;j++)
            {
                que.push(mat[i][j]);
            }
            
            int x=k ;
            
            while(x--)
            {
                int temp = que.front();
                
                que.push(temp);
                
                que.pop();
            }
            
            for(int j=0;j<n;j++)
            {
                mat[i][j] = que.front();
                que.pop();
            }
        }
        return mat;
    }
};
