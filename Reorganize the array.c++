// 11-10-2024

class Solution {
  public:
    vector<int> rearrange(const vector<int>& arr) {
        unordered_set<int> st;
        int n = arr.size();
        
        for(auto it : arr) {
            if(it >= 0)
                st.insert(it);
        }
        
        vector<int> result;
        
        for(int i=0;i<n;i++) {
            if(st.find(i) != st.end())
                result.push_back(i);
            
            else
                result.push_back(-1);
        }
        
        return result;
    }
};
