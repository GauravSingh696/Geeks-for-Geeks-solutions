class Solution {
  public:
    void solve(int i, vector<vector<int>> &result, vector<int> &arr) {
        if(i == arr.size()) {
            result.push_back(arr);
        }
        
        for(int j=i;j<arr.size();j++) {
            swap(arr[i], arr[j]);
            solve(i+1, result, arr);
            swap(arr[i], arr[j]);
        }
    }
    
    vector<vector<int>> permuteDist(vector<int>& arr) {
        vector<vector<int>> result;
        
        solve(0, result, arr);
        
        return result;
    }
};
