class Solution {
  public:
    int countSubstring(string &s) {
        unordered_map<char, int> mp;
        int n = s.size();
        int cnt = 0;
        
        for(int i=0;i<n;i++) {
            char ch = s[i];
            mp[ch]++;
            cnt += mp[ch];
        }
        
        return cnt;
    }
};
