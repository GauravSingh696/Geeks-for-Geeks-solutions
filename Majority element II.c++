class Solution {
  public:
    vector<int> findMajority(vector<int>& nums) {
        vector<int> result;
        unordered_map<int, int> mp;
        
        for(auto &it : nums) {
            mp[it]++;
        }
        
        for(auto it : mp) {
            if(it.second > (nums.size()/3))
                result.push_back(it.first);
        }
        
        sort(result.begin(), result.end());
        
        return result ;
    }
};
