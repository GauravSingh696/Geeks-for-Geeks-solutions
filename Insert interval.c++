class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals, vector<int> &newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> result;
        int prev_start = -1;
        int prev_end   = -1;
        
        for(auto it : intervals) {
            int start = it[0];
            int end   = it[1];
            
            if(prev_start == -1 && prev_end == -1) {
                prev_start = start;
                prev_end   = end;
            }
            
            else {
                if(prev_end < start) {
                    result.push_back({prev_start, prev_end});
                    prev_start = start;
                    prev_end   = end;
                }
                else {
                    prev_end = max(prev_end, end);
                }
            }
        }
        
        result.push_back({prev_start, prev_end});
        
        return result;
    }
};
