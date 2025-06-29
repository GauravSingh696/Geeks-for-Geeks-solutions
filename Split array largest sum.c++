class Solution {
  public:
    bool check(int sum, int k, vector<int> &arr) {
        int temp = 0;
        
        for(int &it : arr) {
            temp += it;
            
            if(temp > sum) {
                k--, temp = it;
            }
        }
        
        return (k > 0 && temp <= sum);
    }
  
    int splitArray(vector<int>& arr, int k) {
        int start = *max_element(arr.begin(), arr.end());
        int end   = accumulate(arr.begin(), arr.end(), 0);
        int result = -1;
        
        while(start <= end) {
            int mid = start + (end - start) / 2;
            
            if(check(mid, k, arr)) {
                result = mid;
                end    = mid - 1;
            }
            else
                start = mid + 1;
        }
        
        return result;
    }
};
