class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int result = *max_element(left.begin(), left.end());
        
        for(int &it : right) {
            result = max(result, n - it);
        }
        
        return result;
    }
};
