class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        if(m >a.size()) return 0;
        
        sort(a.begin(), a.end());
        int result = INT_MAX;
        
        for(int i=0;i<=a.size()-m;i++) {
            result = min(result, a[i+m-1] - a[i]);
        }
        
        return result;
    }
};
