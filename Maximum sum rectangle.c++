class Solution {
  public:
    int maxRectSum(vector<vector<int>> &mat) {
        int result = INT_MIN;
        int n = mat.size();
        int m = mat[0].size();
        
        for(int s=0;s<n;s++) {
            vector<int> temp(m, 0);
            
            for(int i=s;i<n;i++) {
                for(int j=0;j<m;j++) {
                    temp[j] += mat[i][j];
                }
                
                // 1D kadane on temp
                int maxi = INT_MIN;
                int curr = 0;
                
                for(int j=0;j<m;j++) {
                    curr += temp[j];
                    maxi = max(maxi, curr);
                    
                    if(curr < 0)
                        curr = 0;
                }
                
                result = max(result, maxi);
            }
        }
        
        return result;
    }
};
