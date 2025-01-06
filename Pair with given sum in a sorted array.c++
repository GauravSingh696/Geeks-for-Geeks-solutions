class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        unordered_map<int, int> mp;
        
        for(auto it : arr) 
            mp[it]++;
        
        int result = 0;
        
        for(auto it : arr) {
            mp[it]--;
            result +=  mp[target - it];
        }
        
        return result;
    }
};
