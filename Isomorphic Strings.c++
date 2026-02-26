class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        unordered_map<char, char> mp;
        unordered_set<char> st;
        
        for(int i=0;i<s1.size();i++) {
            if(mp.find(s1[i]) == mp.end()) {
                if(st.find(s2[i]) != st.end()) {
                    return false;
                }
                
                mp[s1[i]] = s2[i];
                st.insert(s2[i]);
            } else {
                if(mp[s1[i]] != s2[i]) return false;
            }
        }
        
        return true;
    }
};
