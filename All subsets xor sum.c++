class Solution {
  public:
    int subsetXORSum(vector<int>& arr) {
        int Or = 0;
        int n = arr.size();
        
        for (int x : arr) {
            Or |= x;    
        }
        
        return Or * (1 << (n - 1));
    }
};
