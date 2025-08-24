class Solution {
  public:
    bool solve(int &curr, vector<int> &arr, int &k, int m) {
        int count = 0;
        
        for(int &it : arr) {
            if(it <= curr) {
                count++;
            } else {
                count = 0;
            }
            
            if(count == k) {
                count = 0;
                m--;
            }
        }
        
        return m <= 0;
    }
  
    int minDaysBloom(vector<int>& arr, int k, int m) {
        int res = -1;
        
        int low = 0, high = *max_element(arr.begin(), arr.end());
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(solve(mid, arr, k, m)) {
                high = mid - 1;
                res = mid;
            } else {
                low = mid + 1;
            }
        }
        
        return res;
    }
};
