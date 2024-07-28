// 28-07-2024

class Solution {
  public:

    string removeDups(string str) {
        
        unordered_map<char, int> mp;
        int n = str.length();
        
        string result = "";
        
        for(int i=0;i<n;i++)
        {
            if(mp.find(str[i]) != mp.end())
            {
                mp[str[i]]--;
            }
            
            else
            {
                mp[str[i]]++;
                result.push_back(str[i]);
            }
        }
        
        return result;
        
    }
};
