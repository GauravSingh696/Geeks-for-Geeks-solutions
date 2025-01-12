class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        vector<int> pre(n) , post(n);
        pre[0] = arr[0];
        post[n-1] = arr[n-1];
        
        for(int i=1 ; i<n ; i++) {
            pre[i] = max(arr[i] , pre[i-1]);
        }
        
        for(int i=n-2 ; i>=0 ; i--) {
            post[i] = max(arr[i] , post[i+1]);
        }
        
        int result = 0;
        
        for(int i=1 ; i<n-1 ; i++) {
            int val = min(pre[i] , post[i]);
            
            if(val >= arr[i]) {
                result += val - arr[i];
            }
        }
        
        return result;
    }
};
