class Solution {
  public:
    int kadanesMax(vector<int> &arr, int n) {
        int sum = arr[0];
        int maxSum = arr[0];
        
        for(int i=1;i<n;i++) {
            sum = max(sum + arr[i], arr[i]);
            maxSum = max(maxSum, sum);
        }
        
        return maxSum;
    }
    
    int kadanesMin(vector<int> &arr, int n) {
        int sum = arr[0];
        int minSum = arr[0];
        
        for(int i=1;i<n;i++) {
            sum = min(sum + arr[i], arr[i]);
            minSum = min(minSum, sum);
        }
        
        return minSum;
    }
  
    int maxCircularSum(vector<int> &arr) {
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        
        int minSum = kadanesMin(arr, n);
        int maxSum = kadanesMax(arr, n);
        
        int cirSum = sum - minSum;
        
        if(maxSum > 0) {
            return max(maxSum, cirSum);
        }
        
        return maxSum;
    }
};
