class Solution {
  public:
    bool solve(vector<int>& arr, int sum, int i, int curr) {
        if(curr > sum)
            return false;
        
        if(sum == curr)
            return true;
        
        if(i>=arr.size())
            return false;
    
        if(solve(arr, sum, i+1, curr+arr[i]))
            return true;
            
        solve(arr, sum , i+1, curr);
    }
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        return solve(arr, sum , 0, 0);
    }
};
