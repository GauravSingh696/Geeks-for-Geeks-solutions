class Solution {
  public:
    void solve(vector<int> &arr, int i, set<vector<int>> &res) {
        if(i >= arr.size()) {
            res.insert(arr);
            return;
        }
        
        for(int j=i;j<arr.size();j++) {
            swap(arr[i], arr[j]);
            solve(arr, i+1, res);
            swap(arr[i], arr[j]);
        }
    }
  
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        set<vector<int>> res;
        
        solve(arr, 0, res);
        
        return vector<vector<int>> (res.begin(), res.end());
    }
};
