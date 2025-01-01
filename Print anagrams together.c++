class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        map<string , vector<string>> mp;
        
        for(auto it : arr)  {
            string temp = it;
            sort(temp.begin() , temp.end());
            mp[temp].push_back(it);
        }
        
        vector<vector<string>> result;
        
        for(auto it : mp) {
            result.push_back(it.second);
        }
        
        return result;
    }
};
