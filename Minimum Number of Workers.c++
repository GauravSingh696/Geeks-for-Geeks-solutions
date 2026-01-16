class Solution {
  public:
    int minMen(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> intervals;
        
        for(int i=0;i<n;i++) {
            if(arr[i] != -1) {
                int L = max(0, i-arr[i]);
                int R = min(n-1, i+arr[i]);
                
                intervals.push_back({L,R});
            }
        }
        
        sort(intervals.begin(), intervals.end());
        
        int count = 0, curr_end = 0, i = 0;
        
        while(curr_end < n) {
            int farthest = curr_end - 1;
            
            while(i < intervals.size() && intervals[i].first <= curr_end) {
                farthest = max(farthest, intervals[i].second);
                i++;
            }
            
            if(farthest < curr_end) {
                return -1;
            }
            
            count++;
            curr_end = farthest + 1;
        }
        
        return count;
    }
};
