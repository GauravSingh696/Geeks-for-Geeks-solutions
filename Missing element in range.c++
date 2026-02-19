class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        unordered_set<int> st(arr.begin(), arr.end());
        vector<int> result;
        
        while(low <= high) {
            if(st.find(low) == st.end())    result.push_back(low);
            low++;
        }
        
        return result;
    }
};
