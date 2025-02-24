class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> result(n, 1);
        
        st.push(0);
        
        for(int i=1;i<n;i++) {
            while(!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            
            if(st.empty()) {
                result[i] = i + 1;
            }
            else
                result[i] = i - st.top();
            
            st.push(i);
        }
        
        return result;
    }
};
