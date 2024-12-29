class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        unordered_set<int> st(a.begin() , a.end()) , st1;
        
        for(auto it : b) {
            if(st.find(it) != st.end()) {
                st1.insert(it);
            }
        }
        
        vector<int> vec(st1.begin() , st1.end());
        
        return vec;
    }
};
