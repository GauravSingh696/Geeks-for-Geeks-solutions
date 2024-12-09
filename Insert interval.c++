class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals, vector<int> &newInterval) {
        intervals.push_back(newInterval);
        
        sort(intervals.begin() , intervals.end());
        
        int i=0 , j=1 , n=intervals.size();
        vector<vector<int>> vec;
        
        while(j<n) {
            if(intervals[j][0] > intervals[j-1][1]) {
                vec.push_back({intervals[i][0] , intervals[j-1][1]});
                i=j , j++;
            }
            
            else {
                intervals[j][1] = max(intervals[j][1] , intervals[j-1][1]);
                j++;
            }
        }
        
        vec.push_back({intervals[i][0] , intervals[j-1][1]});
        
        return vec;
    }
};
