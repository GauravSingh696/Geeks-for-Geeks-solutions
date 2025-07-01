class Solution {
  public:
    int substrCount(string &s, int k) {
        unordered_map<char, int> mp;
        
        for(int i=0;i<k;i++) {
            mp[s[i]]++;
        }
        
        int result = 0;
        
        if(mp.size() == k-1)
            result++;
        
        for(int i=k, j=0 ; i<s.size() ; i++, j++) {
            if(mp[s[j]] == 1)
                mp.erase(s[j]);
            
            else
                mp[s[j]]--;
            
            mp[s[i]]++;
            
            if(mp.size() == k-1)
                result++;
        }
        
        return result;
    }
};
