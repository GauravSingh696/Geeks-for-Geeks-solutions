class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        int max_idx = 0 , next_max_idx = arr[0];
        int result = 0;
        
        for(int i=0;i<n-1;i++) {
            if(max_idx == i) {
                max_idx = max(next_max_idx , i+arr[i]);
                next_max_idx = 0;
                result++;
            }
            else {
                next_max_idx = max(next_max_idx, i+arr[i]);
            }
        }
        
        return max_idx>=n-1 ? result : -1 ;
    }
};
