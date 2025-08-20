class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        for(auto it : mat) {
            for(int val : it) {
                if(val == x)
                    return true;
            }
        }
        
        return false;
    }
};
