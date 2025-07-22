class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        set<int> st;
        
        for(int &it : arr) {
            if(it > 0)
                st.insert(it);
        }
            
        int n = st.size();
        int prev = 0;
        
        for(auto &it : st) {
            if(prev + 1 != it)
                return prev + 1;
            
            prev = it;
        }
            
        return prev + 1;
    }
};
