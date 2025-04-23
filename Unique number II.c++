class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        unordered_map<int, int> mp;
        
        for(auto &it : arr) {
            mp[it]++;
        }
        
        vector<int> vec;
        
        for(auto &it : mp) {
            if(it.second == 1)
                vec.push_back(it.first);
        }
        
        sort(vec.begin(), vec.end());
        
        return vec;
    }
};
