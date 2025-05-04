class Solution {
  public:
    int findSubString(string& str) {
        int result = INT_MAX;
        int i=0 , j=0 , n=str.size();
        
        unordered_set<char> st(str.begin(), str.end());
        unordered_map<char, int> mp;
        
        int s2 = st.size();
        
        while(j<n) {
            mp[str[j]]++;
            int s1 = mp.size();
            
            while(i<=j && s1 == s2) {
                result = min(result, j-i+1);
                
                mp[str[i]]--;
                
                if(mp[str[i]] == 0)
                    mp.erase(str[i]);
                
                s1 = mp.size();
                i++;
            }
            
            j++;
        }
        
        return result;
    }
};
