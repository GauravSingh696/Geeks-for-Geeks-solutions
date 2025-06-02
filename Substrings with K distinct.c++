class Solution {
  public:
    int solve(string &s, int k) {
        unordered_map<char, int> mp;
        int left = 0;
        int count = 0;
        
        for(int right=0;right<s.size();right++) {
            mp[s[right]]++;
            
            while(mp.size() > k) {
                mp[s[left]]--;
                
                if(mp[s[left]] == 0)
                    mp.erase(s[left]);
                
                left++;
            }
            
            count += right - left + 1;
        }
        
        return count;
    }
  
    int countSubstr(string& s, int k) {
        return solve(s, k) - solve(s, k-1);
    }
};
