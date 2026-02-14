class Solution {
  public:
    bool check(vector<int> &a, int n, int k, int mid) {
        int sum = 0, cnt = 1;
        
        for(int i=0;i<n;i++) {
            if(sum + a[i] <= mid) {
                sum += a[i];
            } else {
                cnt++, sum = a[i];
            }
        }
        
        return (cnt <= k) ? true : false;
    }
  
    int minTime(vector<int>& arr, int k) {
        int n = arr.size();
        int low = arr[0], high = 0;
        int ans = -1;
        
        for(int i=0;i<n;i++) {
            if(arr[i] > low)
                low = arr[i];
            
            high += arr[i];
        }
        
        
        while(low <= high) {
            int mid = (low + high) / 2;
            
            if(check(arr, n, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};
