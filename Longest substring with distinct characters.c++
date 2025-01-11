class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        unordered_map<char,int> mp;
        
        int i=0 , j=0 , n=s.size();
        int result = 1;
        
        while(j<n) {
            if(mp[s[j]] != 0) {
                result = max(result , j-i);
                
                while(i<n && mp[s[j]]!=0) {
                    mp[s[i]]--;
                    i++;
                }
            }
            
            mp[s[j]]++;
            j++;
        }
        
        result = max(result , n-i);
        
        return result;
    }
};
