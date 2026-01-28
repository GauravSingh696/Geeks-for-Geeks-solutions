class Solution {
  public:
    void solve(int idx, int end, long long sum, vector<int> &arr, vector<long long> &result) {
        if(idx == end) {
            result.push_back(sum);
            return ;
        }
        
        solve(idx+1, end, sum+arr[idx], arr, result);
        solve(idx+1, end, sum, arr, result);
    }
  
    int countSubset(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> left(arr.begin(), arr.begin()+n/2);
        vector<int> right(arr.begin()+n/2, arr.end());
        vector<long long> sumL, sumR;
        
        solve(0, left.size(), 0, left, sumL);
        solve(0, right.size(), 0, right, sumR);
        
        sort(sumR.begin(), sumR.end());
        
        long long result = 0;
        
        for(auto it : sumL) {
            long long temp = k - it;
            
            result += upper_bound(sumR.begin(), sumR.end(), temp) - lower_bound(sumR.begin(), sumR.end(), temp);
        }
        
        return result;
    }
};
