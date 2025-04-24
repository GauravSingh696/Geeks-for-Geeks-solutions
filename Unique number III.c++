class Solution {
  public:
    int getSingle(vector<int> &arr) {
        unordered_map<int, int> mp;
        
        for(auto &it : arr) {
            mp[it]++;
        }
        
        for(auto &it : mp) {
            if(it.second == 1)
                return it.first;
        }
        
        return -1;
    }
};
