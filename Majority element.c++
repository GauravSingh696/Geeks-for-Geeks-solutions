class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        unordered_map<int, int> mp;
        int n = arr.size()/2;
        
        for(auto &it : arr) {
            mp[it]++;
            
            if(mp[it] > n)
                return it;
        }
        
        return -1;
    }
};
