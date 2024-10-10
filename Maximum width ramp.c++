// 10-10-2024

class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        int n = arr.size();
        int result = 0;
        unordered_map<int , int> mp;
        
        for(int i=0;i<n;i++) {
            mp[arr[i]] = i;
        }
        
        for(int i=0;i<n;i++) {
            result = max(result , mp[arr[i]]-i);
        }
        
        return result;
    }
};
