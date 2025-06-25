class Solution {
  public:
    bool sameFreq(string& s) {
        if(s.size() == 1)
            return true;
        
        unordered_map<char, int> mp;
        
        for(char &ch : s) {
            mp[ch]++;
        }
        
        unordered_set<int> st;
        
        for(auto &j : mp) {
            if(j.second > 0)
                st.insert(j.second);
        }
        
        if(st.size() == 1)
            return true;
        
        for(auto &i : mp) {
            i.second--;
            
            st.clear();
            
            for(auto &j : mp) {
                if(j.second > 0)
                    st.insert(j.second);
            }
            
            if(st.size() == 1)
                return true;
            
            i.second++;
        }
        
        return false;
    }
};
