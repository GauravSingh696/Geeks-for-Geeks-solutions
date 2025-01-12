class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        vector<int> pre(n) , post(n);
        pre[0] = arr[0];
        post[n-1] = arr[n-1];
        
        for(int i=1 ; i<n ; i++) {
            if(arr[i] < pre[i-1])
                pre[i] = pre[i-1];
            
            else
                pre[i] = arr[i];
        }
        
        for(int i=n-2 ; i>=0 ; i--) {
            if(arr[i] < post[i+1])
                post[i] = post[i+1];
            
            else
                post[i] = arr[i];
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
